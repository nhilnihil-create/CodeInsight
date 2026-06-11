#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  int curr = 0;
  for(int i=0; i<n; i++){
    if(arr[i]==curr+1) curr++;
  }
  if(!curr) cout<<-1;
  else cout<<n-curr;
}