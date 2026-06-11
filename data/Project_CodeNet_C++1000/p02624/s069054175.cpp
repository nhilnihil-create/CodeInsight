#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

ll g_i(ll x,ll n) {
  ll res = 0;

  ll y = n/x;

  for(ll i = 1; i <= y; i++) {
    res += i * x;
  }

  return res;
}

int main() {
  ll n; cin >> n;
  ll ans = 0;

  for(ll i = 1; i <= n; i++) {
    ans += g_i(i,n);
  }

  cout << ans << endl;
}
