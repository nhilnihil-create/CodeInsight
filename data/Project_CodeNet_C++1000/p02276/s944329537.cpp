#include<bits/stdc++.h>
#define N 100001
using namespace std;
int n,A[N];

int partition(int p,int r){
  int x=A[r];
  int i=p-1,t;
  for(int j=p;j<r;j++)
    if(A[j]<=x){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
  int r=partition(0,n-1);
  for(int i=0;i<n;i++){
    if(i)cout<<' ';
    if(r==i)cout<<'[';
    cout<<A[i];
    if(r==i)cout<<']';
  }
  cout<<endl;
  return 0;
}