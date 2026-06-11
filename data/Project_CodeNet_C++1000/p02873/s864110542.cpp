#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  string S; cin>>S;
  ll N=S.size()+1;
  vector<ll> A(N,0);
  rep(i,N)
  {
    if(i==0) {continue;}
    if(S.at(i-1)=='<') {A.at(i)=A.at(i-1)+1;}
  }
  /*
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<A.at(i);
  }
  cout<<endl;
  */
  
  
  reverse(S.begin(),S.end());
  reverse(A.begin(),A.end());
  rep(i,N)
  {
    if(i==0) {continue;}
    if(S.at(i-1)=='>') {A.at(i)=max(A.at(i-1)+1,A.at(i));}
  }
  /*
  reverse(A.begin(),A.end());
  rep(i,N)
  {
    if(i!=0) {cout<<" ";}
    cout<<A.at(i);
  }
  cout<<endl;
  */
  
  ll ans=0;
  rep(i,N)
  {
    ans+=A.at(i);
  }
  cout<<ans<<endl;
  return 0;
}
