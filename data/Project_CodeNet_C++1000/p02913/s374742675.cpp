#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

// res[i] := S[i:] と S[0: ] との最長共通部分列の長さ。O(|S|)
vi Zalgorithm(const string &S) {
  int N = (int)S.size();
  vi res(N);
  res[0] = N;
  int i = 1, j = 0;
  while(i < N) {
    while(i + j < N && S[j] == S[i + j]) ++j;
    res[i] = j;
    if(j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while(i + k < N && k + res[k] < j) res[i + k] = res[k], ++k;
    i += k, j -= k;
  }
  return res;
}

int main() {
  ll n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  rep(i, n) {
    string t = s.substr(i, n - i);
    vi z = Zalgorithm(t);
    rep(j, n - i) ans = max(ans, min(j, ll(z[j])));
  }
  cout << ans << endl;
}