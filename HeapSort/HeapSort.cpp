// King TT
// C++ program for implementation of Heap Sort
// Adapted from progamiz.com
#include <iostream>
#include <stdlib.h>
using namespace std;

    //Thus, to maintain the max-heap property in a tree where both sub-trees are max-heaps,
    // we need to run heapify on the root element repeatedly until it is larger than its children or it becomes a leaf node.

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    // If left index is less than size of array, and it is greater than its root, then swap.
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // likewise for right
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        std::cout << "|"<< arr[i] << "| \t";
    std::cout<<endl;

}

void createArray(int *iterator, std::size_t sizeOfArray) {

    /* The pointer iterator is pointing to the first element of
 * the array and the sizeOfArray is the size of the array. In the
 * loop we are incrementing pointer so that it points to
 * the next element of the array on each increment.
    **/

    for (int counter = 0; counter < sizeOfArray; counter++)
    {
        *iterator = (rand() % 1000) + 1;
        counter++;
    }

    std::cout<<"The array before heapify \n";
    printArray(iterator, sizeOfArray);

}



int main() {
    while (true) {
        int size;
        std::cout << " Select size of array that you would like to sort or enter -1 to exit" << std::endl << ">> ";
        std::cin >> size;
        std::cout << endl;

        if (size <= 0)
        {
            return -1;
        }

        int arr[size];
        //create Array
        createArray(arr, size);
        std::cout << "--------------------------------------" << std::endl;
        //heapSort
        heapSort(arr, size);
        cout << "Sorted array is \n";
        printArray(arr, size);

        std::cout<<endl<<endl;


    }
}