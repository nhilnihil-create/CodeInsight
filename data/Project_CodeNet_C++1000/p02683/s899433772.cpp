#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int n,m,x;
  cin>>n>>m>>x;
  int ans=10101010;
  int a[12][12];
  vector<int>c(n);
  rep(i,n){
  	cin>>c.at(i);
    	rep(j,m) cin>>a[i][j];
  }
  rep(s,1<<n){
    int cost=0;
    vector<int>d(m,0);
  	rep(i,n){
    	if(s>>i &1){
        	cost+=c.at(i);
          	rep(j,m) d.at(j)+=a[i][j];
        }
    }
    bool ok=true;
    rep(j,m) if(d.at(j) <x) ok=false;
    if(ok) ans=min(ans,cost);
   }
  if(ans==10101010) cout<<-1<<endl;
  else cout<<ans<<endl;
}
// ビット全探索を使って考える