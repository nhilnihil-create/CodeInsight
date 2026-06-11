#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

void z_algorithm(string &s, vector<ll>&ans) {
  ans.resize(s.size());
  ans[0] = s.size();
  int i = 1, j = 0;
  while (i < s.size()) {
    while ((i + j < s.size()) && (s[j] == s[i+j])) j++;
    ans[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while ((i + k < s.size()) && (k + ans[k] < j)) {
      ans[i+k] = ans[k];
      k++;
    }
    i += k; j -= k;
  }
  return;
} 

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  vector<ll> a;
  for (int i = 0; i < n; i++) {
    string sd = s.substr(i);
    z_algorithm(sd, a);
    ll temp = 0;
    for (int j = 0; j < sd.size(); j++) {
      temp = max(temp, min((ll)j, (ll)a[j]));
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
