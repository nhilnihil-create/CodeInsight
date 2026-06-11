#include<iostream>
#include<array>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n],count[n+1] ;
  for(int i=0;i<n+1;i++){
    count[i]=0;
  }
  for(int i=0;i<n-1;i++){
    cin>>arr[i];
    count[arr[i]]++;
  }
  for(int i=1;i<=n;i++){
    cout<<count[i]<<"\n";
  }
  return 0;
}