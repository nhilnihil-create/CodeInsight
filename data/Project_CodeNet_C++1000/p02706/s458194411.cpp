#include<iostream>
using namespace std;
int main(){
  long int n,m,sum=0;
  cin>>n>>m;
  long int arr[m];
  for(int i=0;i<m;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  if(sum==n){
    cout<<"0";
  }
  else if(sum<n){
    cout<<n-sum;
  }
  else
    cout<<"-1";
  return 0;
}