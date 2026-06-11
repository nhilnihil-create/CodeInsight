#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
  int n,x,p,ans=10000,a[200]={};
  cin>>x>>n;
  for(int i=0;i<n;i++){
    cin>>p;
    a[p]=1;
  }
  for(int i=0;i<=101;i++){
    if(a[i]==0 && abs(x-i)<abs(x-ans)) ans=i;
    if(abs(x-i)==abs(x-ans) && i<ans) ans=i;
  }
  cout<<ans<<"\n";
  return(0);
}