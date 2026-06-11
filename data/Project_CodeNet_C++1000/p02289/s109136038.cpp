#include <iostream>
#include <string>
using namespace std;
int H=0;
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
        int tmp=A[i];
        A[i]=A[largest];
        A[largest]=tmp;
        maxheapify(A,largest);
    }
}    
int extract(int A[]){
    if(H<1){
        return false;
    }
    int max=A[1];
    A[1]=A[H];
    H=H-1;
    maxheapify(A,1);
    return max;
}
void increasekey(int A[],int i,int key){
    if(key<A[i]){
        return;
    }
    A[i]=key;
    while(i>1 && A[i/2]<A[i]){
        int tmp=A[i];
        A[i]=A[i/2];
        A[i/2]=tmp;
        i=i/2;
    }
}

void insert(int A[],int key){
    H++;
    A[H]=-1000000000;
    increasekey(A,H,key);
}
int main(){
    string s;
    int key,A[10000000];
    cin>>s;
    while(s!="end"){
        if(s=="insert"){
            cin>>key;
            insert(A,key);
        }
        else{
            cout<<extract(A)<<endl;
        }
        cin>>s;
    }
    return 0;
}
