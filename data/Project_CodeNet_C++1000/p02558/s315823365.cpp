#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200005;
const int MOD =1000000007;

signed main(){
int n,q;
cin>>n>>q;
int t,u,v;
dsu d(n);
for(int i=0;i<q;i++){
  cin>>t>>u>>v;
  if(t){
    if(d.same(u,v))cout<<1<<endl;
    else cout<<0<<endl;
  }else{
    d.merge(u,v);
  }
}
}