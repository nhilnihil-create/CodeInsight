#include <iostream>
using namespace std;
void maxHeapify(int *arr, int i, int n){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= n && arr[left] > arr[i])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;
    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        maxHeapify(arr, largest, n);
    }
}
void buildMaxHeap(int *arr, int n){
    for(int i = n/2; i >= 1; i--){
        maxHeapify(arr, i, n);
    }
}
int main(){
    unsigned long long int n, m;
    cin >> n;
    cin >> m;
    unsigned long long int sum = 0;
    int *prices = new int[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> prices[i];
        sum += prices[i];
    }
    buildMaxHeap(prices, n);
    for(int i = m; i > 0; i--){
        sum -= prices[1];
        prices[1] /= 2;
        sum += prices[1];
        maxHeapify(prices, 1, n);
    }
    cout << sum;
}