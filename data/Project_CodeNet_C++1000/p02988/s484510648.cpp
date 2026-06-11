#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int sum=0;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=1;i<n-1;i++){
    if(A[i-1]<A[i]&&A[i]<A[i+1]){
      sum++;
    }else if(A[i-1]>A[i]&&A[i]>A[i+1]){
      sum++;
    }
  }
  cout<<sum<<endl;
}