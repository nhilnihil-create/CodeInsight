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
  atcoder::fenwick_tree<ll> ft(n);
  rep(i,n){
    ll k;cin >> k;
    ft.add(i,k);
  }
  while(Q--){
    ll T,l,r;cin >> T >> l >> r;
    if(!T){
      ft.add(l,r);
    }else{
      cout << ft.sum(l,r) << "\n";
    }
  }

  


  return 0;
}