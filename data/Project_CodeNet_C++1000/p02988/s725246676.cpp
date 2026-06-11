#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  ll res = 0;
  rep(i, n-2) {
    if (v.at(i)<v.at(i+1) && v.at(i+1)<v.at(i+2)) res++;
    if (v.at(i+2)<v.at(i+1) && v.at(i+1)<v.at(i)) res++;
  }
  cout << res << endl;
}