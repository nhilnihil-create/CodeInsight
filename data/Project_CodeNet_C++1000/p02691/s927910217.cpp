#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  vector<ll> list_a;
  unordered_map<ll, int> candidates;

  rep(i, n) {
    int a;
    cin >> a;
    list_a.push_back(a + i + 1);
    candidates[i + 1 - a]++;
  }

  ll count = 0;

  rep(i, n) { count += candidates[list_a[i]]; }

  cout << count << endl;

  return 0;
}
