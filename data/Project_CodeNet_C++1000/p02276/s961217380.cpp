#include<iostream>
using namespace std;
int n,A[100000];
int partition(int p,int r){
  int x=A[r];
  int i=p-1;
  for(int j=p;j<r;j++)
    if(A[j]<=x)swap(A[++i],A[j]);
  swap(A[i+1],A[r]);
  return i+1;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
  int idx=partition(0,n-1);
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    if(i==idx)cout<<"["<<A[i]<<"]";
    else cout<<A[i];
  }
  cout<<endl;
  return 0;
}