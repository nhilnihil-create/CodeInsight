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
  ll N,A,B,C,D,i;string S;
  cin>>N>>A>>B>>C>>D>>S;
  bool x=true,y=false;
  FOR(i,min(A,B),max(C,D)-1)if(S[i]=='#'&&S[i+1]=='#')x=false;
  FOR(i,max(A,B)-1,min(C,D))if(S[i-1]=='.'&&S[i]=='.'&&S[i+1]=='.')y=true;
  if(x&&(C<D||y))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}