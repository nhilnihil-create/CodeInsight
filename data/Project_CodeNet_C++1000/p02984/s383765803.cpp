#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,S=0;cin>>N;ll A[N+2];A[0]=0;A[1]=0;
  REP(i,N){cin>>A[i+2];S+=A[i+2];A[i+2]+=A[i];}
  REP(i,N-1)cout<<2*(A[i+1]+A[N+1-i%2]-A[i])-S<<" ";
  cout<<2*(A[i+1]+A[N+1-i%2]-A[i])-S<<endl;
  return 0;
}