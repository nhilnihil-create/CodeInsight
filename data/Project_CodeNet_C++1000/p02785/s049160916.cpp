#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  long long arr[n];
  int sz=n;
  while(--n>-1){
    cin>>arr[n];
  }
  
  sort(arr,arr+sz);
  
  long long ans =0;
  int i=0;
  k=sz-k;
  while(i<k){
    ans+=arr[i++];
  }
  cout<<ans<<"\n";
  return 0;
}
  
