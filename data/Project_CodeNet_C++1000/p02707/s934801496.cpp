#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> num(n);
  rep(i, n - 1) {
    cin >> a[i];
    num[a[i] - 1]++;
  }
  rep(i, n) cout << num[i] << endl;
  return 0;
}