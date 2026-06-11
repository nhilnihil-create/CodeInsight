#include <iostream>
#define MAX 2000000
#define INFTY 2000000000

using namespace std;

int A[MAX+1], h;

void heapIncreaseKey(int i, int key){
    if(key < A[i]) cerr << "new key is smaller than current key" << endl;
    A[i] = key;
    while(i > 1 && A[i/2] < A[i]){
        int tmp = A[i/2];
        A[i/2] = A[i];
        A[i] = tmp;
        i /= 2;
    }
}

void maxHeapInsert(int key){
    h++;
    A[h] = -INFTY;
    heapIncreaseKey(h, key);
}

void maxHeapify(int i){
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;
    if(l <= h && A[l] > A[i]) largest = l;
    else largest = i;
    if(r <= h && A[r] >  A[largest]) largest = r;
    if(largest != i){
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        maxHeapify(largest);
    }
}

int heapExtractMax(){
    if(h < 1) cerr << "head underflow" << endl;
    int max = A[1];
    A[1] = A[h];
    h--;
    maxHeapify(1);
    return max;
}

int main(){
    string com;
    int key;
    
    cin >> com;
    while(com != "end"){
        if(com == "insert"){
            cin >> key;
            maxHeapInsert(key);
        }
        else cout << heapExtractMax() << endl;
        cin >> com;
    }

    return 0;
}
