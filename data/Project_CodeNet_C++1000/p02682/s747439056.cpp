#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int ans=0;
  while(a>0){
    ans++;
    a--;
    k--;
    if(k==0){cout<<ans<<endl;return 0;}
  }
  while(b>0){
    b--;
    k--;
    if(k==0){cout<<ans<<endl;return 0;}
  }
  while(c>0){
    ans--;
    c--;
    k--;
    if(k==0){cout<<ans<<endl;return 0;}
  }
  return 0;
}