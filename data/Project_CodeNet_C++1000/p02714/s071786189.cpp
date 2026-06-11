#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N; cin>>N;
  string S; cin>>S;
  
  
  vector<vector<ll>> vec(N,vector<ll>(3,0));//R,G,B順で
  reverse(S.begin(),S.end());
  rep(i,N)
  {
    if(i==0) {continue;}
    if(S.at(i-1)=='R') {vec.at(i).at(0)++;}
    if(S.at(i-1)=='G') {vec.at(i).at(1)++;}
    if(S.at(i-1)=='B') {vec.at(i).at(2)++;}
    rep(j,3)
    {
      vec.at(i).at(j)+=vec.at(i-1).at(j);
    }
  }
  reverse(S.begin(),S.end());
  reverse(vec.begin(),vec.end());
  //cout<<S<<endl;
  /*
  rep(i,N)
  {
    rep(j,3)
    {
      if(j!=0) {cout<<" ";}
      cout<<vec.at(i).at(j);
    }
    cout<<endl;
  }
  */
  ll ans=0;
  for(ll i=0;i<N;i++)
  {
    for(ll j=i+1;j<N;j++)
    {
      //if(j!=i+1) {cout<<" ";}
      if(S.at(i)==S.at(j)) {/*cout<<ans*/; continue;}
      if(S.at(i)=='R'&&S.at(j)=='G'||S.at(i)=='G'&&S.at(j)=='R') {ans+=vec.at(j).at(2); if(2*j-i<N&&S.at(2*j-i)=='B') {ans--;}}
      if(S.at(i)=='G'&&S.at(j)=='B'||S.at(i)=='B'&&S.at(j)=='G') {ans+=vec.at(j).at(0); if(2*j-i<N&&S.at(2*j-i)=='R') {ans--;}}
      if(S.at(i)=='B'&&S.at(j)=='R'||S.at(i)=='R'&&S.at(j)=='B') {ans+=vec.at(j).at(1); if(2*j-i<N&&S.at(2*j-i)=='G') {ans--;}}
      //cout<<ans;
    }
    //cout<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
