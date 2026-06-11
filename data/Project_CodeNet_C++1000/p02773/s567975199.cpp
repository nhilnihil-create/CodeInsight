#include "bits/stdc++.h"
#define F first
#define S second
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  map<string, ll>mp;
  ll n = 0;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ++mp[s];
  }
  ll maxm = 0;
  for (auto i : mp) {
    maxm = max(i.S, maxm);
  }
  for (auto i : mp) {
    if (i.S == maxm)
      cout << i.F << "\n";
  }
}
