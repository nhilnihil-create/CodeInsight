#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  map<string, ll> anaglam;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    anaglam[s[i]]++;
  }
  ll ans = 0;
  for (auto x : anaglam) {
    ll num = x.second;
    ans += num*(num-1)/2;
  }
  cout << ans << endl;
}
