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
  ll N,i;cin>>N;ll A[N];
  REP(i,N)cin>>A[i];sort(A,A+N);
  if((A[0]==0&&A[N-1]==0)||(N%3==0&&A[0]==A[N/3-1]&&A[N/3]==A[2*N/3-1]&&A[2*N/3]==A[N-1]&&((A[0]^A[N/3])^A[2*N/3])==0))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}