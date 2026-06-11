#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,ans=0;cin>>N;ll A[N],X[N],Y[N];REP(i,N){cin>>A[i];X[i]=i-A[i];Y[i]=i+A[i];}
  sort(X,X+N);sort(Y,Y+N);
  REP(i,N)ans+=upper_bound(X,X+N,Y[i])-lower_bound(X,X+N,Y[i]);
  cout<<ans<<endl;
  return 0;
}