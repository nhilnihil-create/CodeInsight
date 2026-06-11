#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,x,ans;
  ans=0;
  cin>>n>>x;
  if(n%x==0){
    ans=n/x;
  }else{
    ans=n/x;
    ans++;
  }
  cout<<ans;
}