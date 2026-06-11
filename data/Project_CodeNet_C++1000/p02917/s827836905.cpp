#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;
  cin>>n;
  int b[n+1];
  for(int i=1;i<n;i++){
  	cin>>b[i];
  }
  b[0]=b[1];
  b[n]=b[n-1];
  for(int i=0;i<n;i++){
  	ans+=min(b[i],b[i+1]);
  }
  cout<<ans;
}