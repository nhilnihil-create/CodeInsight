#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int t= *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for (int j=low; j<= high-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high )
    {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    if (N>=1 && N<=1000 && K>=1 && K<=N)
    {
        int total=0;
        int *price=new int[N];
        for (int i=0; i<N; i++)
            cin>>price[i];
        quickSort(price, 0, N-1);
        for (int i=0; i<K; i++)
            total+=price[i];
        cout<<total;
    }
    return 0;
}