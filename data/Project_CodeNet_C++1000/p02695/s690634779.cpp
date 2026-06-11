#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,L,R) for(i=L;i<R;i++)
#define REP(i,N) FOR(i,0,N)
int main(){
  ll N,M,Q,i,j,ans=0;cin>>N>>M>>Q;ll X[4][Q],A[N];REP(i,N)A[i]=1;
  REP(i,Q)REP(j,4)cin>>X[j][i];
  while(1){
    ll p=0;
    REP(i,Q)if(A[X[1][i]-1]-A[X[0][i]-1]==X[2][i])p+=X[3][i];
    ans=max(ans,p);
    if(A[0]==M)break;i=N-1;while(A[i]==M)i--;A[i]++;FOR(j,i+1,N)A[j]=A[i];
  }
  cout<<ans<<endl;
  return 0;
}