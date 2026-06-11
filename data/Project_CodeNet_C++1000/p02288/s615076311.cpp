#include <iostream>
#include <algorithm>
using namespace std;
int H;
void maxheapify(int A[],int i){
    int largest;
    int l=2*i;
    int r=(2*i)+1;
    if(l<=H && A[l]>A[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=H && A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        maxheapify(A,largest);
    }
}
void build(int A[]){
    for(int i=H/2;i>0;i--){
        maxheapify(A,i);
    }
}
int main(){
    int A[10000000];
    cin>>H;
    for(int i=1;i<=H;i++){
        cin>>A[i];
    }
    build(A);
    for(int i=1;i<=H;i++){
        cout<<" "<<A[i];
    }
    cout<<endl;
    return 0;
}
