#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int ans=0;
  int co=0;
  rep(i,n-1){
    if(s.at(i)==s.at(i+1)){
      ans++;
    }
    else{
      co++;
    }
  }
  ans=min(ans+2*k,n-1);
  cout<<ans<<endl;
}