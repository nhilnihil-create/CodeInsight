#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

ll combination(ll n,ll k){//組み合わせ
  ll ans = 1;
  if (k == 1){
    return n / k;
  }
  ans = n * combination(n-1, k-1) / k;
  return ans;
}

int main(){
  int n;
  cin >> n;
  map<int, int> m;
  vi vec(n);
  rep(i,n){
    int j;
    cin >> j;
    m[j]++;
    vec.at(i) = j;
  }
  // for (auto p : m){
  //   if (p.second == 1){
  //     m.erase(p.first);
  //   }
  // }
  // for (auto p : m){
  //   printf("%d %d\n", p.first, p.second);
  // }

  ll cnt = 0;
  for (auto p : m){
    cnt += combination(p.second, 2);
  }
  // cout << cnt << endl;

  rep(i,n){
    ll ans = cnt + (combination(m[vec.at(i)]-1, 2) - combination(m[vec.at(i)], 2));
    cout << ans << endl;
  }
  return 0;
}
