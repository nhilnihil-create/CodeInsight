#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,L,R) for(i=L;i<R;i++)
#define REP(i,N) FOR(i,0,N)
int main(){
  ll i,j,H,W,A,B;cin>>H>>W>>A>>B;
  REP(i,H){
    REP(j,W)cout<<(i<B^j<A);
    cout<<endl;
  }
  return 0;
}