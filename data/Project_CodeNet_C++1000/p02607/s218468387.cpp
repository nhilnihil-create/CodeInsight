#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int arr[n+1];
  int cnt=0;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
    if(i%2 && arr[i]%2)
      cnt++;
  }
  cout<<cnt;
  return 0;
}