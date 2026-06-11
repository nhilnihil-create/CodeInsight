#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  int n;
  cin >> n;
  ll res = 0;
  for(ll i = 1;i <= n;i++)res += i*(i+1)/2;
  rep(i,n-1){
    ll u,v;cin >> u >> v;
    if(u > v)swap(u,v);
    res -= u*(n-v+1);
  }
  cout << res << endl;



  return 0;
}