#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,K; cin>>N>>K;
  vector<ll> A(N);
  vector<ll> list(2001,0);
  rep(i,N)
  {
    cin>>A.at(i);
    ll a=A.at(i);
    if(a!=2000) {list.at(a+1)++;}
  }
  rep(i,2000)
  {
    list.at(i+1)+=list.at(i);
  }  
  
  ll ans=0;
  rep(i,N)
  {
    ll count=0;
    for(int j=i+1;j<N;j++)
    {
      if(A.at(i)>A.at(j)) {count++;}
    }
    ll a=A.at(i);
    ans+=count*K%MOD+K*(K-1)/2%MOD*list.at(a)%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}
