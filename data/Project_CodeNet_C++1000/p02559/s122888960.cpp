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
int n,q,a;
cin>>n>>q;
fenwick_tree<int> tr(n);
for(int i=0;i<n;i++){
  cin>>a;
  tr.add(i,a);
}
int p,l,r;
for(int i=0;i<q;i++){
  cin>>p>>l>>r;
  if(p){
    cout<<tr.sum(l,r)<<endl;
  }else tr.add(l,r);
}
}