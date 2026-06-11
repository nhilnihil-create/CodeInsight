#include <iostream>
#include<algorithm>
using namespace std;
int n;
int partition(int A[],int p,int r){
    int x=A[r],i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
   swap(A[i+1],A[r]);
    return i+1;
}
int main(){
    cin>>n;
    int A[100001];
    for(int i=0;i<n;i++) cin>>A[i];
    int q=partition(A,0,n-1); 
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        if(i==q) cout<<"["<<A[i]<<"]";
        else cout<<A[i];
    } 
    cout<<endl;
    return 0;
}
