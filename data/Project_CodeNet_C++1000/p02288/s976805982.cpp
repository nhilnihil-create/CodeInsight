#include <iostream>


using namespace std;
int a[100000000];
int largest,n,l,r;
int i,x;
int maxHeapify(int a[],int i){
    l=2*i+1;
    r=2*i+2;
    if(l<=n && a[l]>a[i]){
        largest =l;
    }
    else{
        largest =i;
    }
    if(r<=n && a[r]>a[largest]){
        largest =r;
    }
    if(largest!=i){
        x=a[i];
        a[i]=a[largest];
        a[largest]=x;
        maxHeapify(a,largest);
    }
    return 0;
}
void buildMaxHeap(int a[]){
    for(int i=n/2;i>=0;i--){
        maxHeapify(a,i);
    }
}
int main(void){
    
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    buildMaxHeap(a);
    for(int i=0;i<n;i++){
        cout <<" "<< a[i];
        if(i==n-1){
            cout << endl;
        }
    }
    
}

