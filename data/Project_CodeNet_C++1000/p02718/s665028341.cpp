#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  cin>>n>>m;
  int arr[n];
  for(int i=0; i<n; i++) cin>>arr[i];
  int total = 0;
  for(int i=0; i<n; i++) total+=arr[i];
  int ret = 0;
  for(int i=0; i<n; i++){
  	if(arr[i]*4*m>=total) ret++;
  }
  if(ret>=m) cout<<"Yes";
  else cout<<"No";
}