#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  int N,K,S; cin>>N>>K>>S;
  if(K==N)
  {
    rep(i,N)
    {
      if(i!=0) {cout<<" ";}
      cout<<S;
    }
    cout<<endl;
    return 0;
  }  
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    if(i<K) {cout<<S; continue;}
    if(S==1000000000) {cout<<1; continue;}
    cout<<1000000000;
  }
  cout<<endl;
  return 0;
}
