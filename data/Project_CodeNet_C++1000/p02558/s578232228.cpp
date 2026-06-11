#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n,Q;
  cin >> n >> Q;
  atcoder::dsu d(n);
  while(Q--){
    int T;cin >> T;
    int u,v;cin >> u >> v;
    if(!T){
      d.merge(u,v);
    }else{
      cout << d.same(u,v) << "\n";
    }
  }

  


  return 0;
}