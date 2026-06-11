#include <bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)

using namespace std;

int main()
{
  int N; cin>>N;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];
  vector<ll> b(N),c(N);
  rep(i,N) b[i] = a[i]+i;
  rep(i,N) c[i] = i-a[i];
  map<ll,int> Map;
  ll ans=0;
  RFOR(i,N-1,1){
    Map[c[i]]++;
    ans+=Map[b[i-1]];
  }
  cout<<ans<<endl;
  return 0;
}