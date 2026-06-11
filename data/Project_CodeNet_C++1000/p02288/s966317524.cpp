#include <iostream>

using namespace std;

int num_elem;

void maxheapfy(int* array, int index)
{
    int l = 2 * index + 1 < num_elem ? 2 * index + 1 : -1;
    int r = 2 * index + 2 < num_elem ? 2 * index + 2 : -1;
    if(l == -1 && r == -1) return;
    int largest = index;
    if(array[largest] < array[l])
    {
        largest = l;
    }
    if(r != -1 && array[largest] < array[r])
    {
        largest = r;
    }
    if(largest != index)
    {   
        swap(array[largest], array[index]);
        maxheapfy(array, largest);
    }
}

void buildmaxheap(int* array)
{
    for(int i=(num_elem) / 2 - 1; i >= 0; --i)
    {
        maxheapfy(array, i);
    }
}

int main()
{
    int array[500001];
    cin >> num_elem;
    for(int i=0;i<num_elem;++i) cin >> array[i];
    buildmaxheap(array);
    for(int i=0;i<num_elem;++i) cout << " " << array[i];
    cout << endl;
}

