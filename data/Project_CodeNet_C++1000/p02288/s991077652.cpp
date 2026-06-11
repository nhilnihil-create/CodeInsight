#include<iostream>
#define MAXNUM 500001
using namespace std;
int A[MAXNUM];
int n;

int parent(int i){
    return i/2;
}
int left(int i){
    return i*2;
}
int right(int i){
    return i*2+1;
}

void maxHeapify(int A[],int i){
    int l=left(i),r=right(i);
    int k=0;
    if(l<=n && A[l]>A[i]){
        k=l;
    }else k=i;
    if(r<=n && A[r]>A[k])
        k=r;
    if(k!=i){
        int temp=A[k];
        A[k]=A[i];
        A[i]=temp;
        maxHeapify(A,k);
    }
}
void buildMaxHeap(int A[],int n){
    for(int i=n/2;i>0;i--){
        maxHeapify(A,i);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    buildMaxHeap(A,n);
    for(int i=1;i<=n;i++){
        cout<<' ' <<A[i];
    }
    cout<<endl;
    return 0;
}

