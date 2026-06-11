#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int ng = 0;
  rep(i, n + 1) {
    if(s[i] == '1')
      ng++;
    else
      ng = 0;
    if(ng == m) {
      cout << -1 << endl;
      return 0;
    }
  }
  vi ans;
  while(n) {
    for(int i = m; i >= 1; i--) {
      int j = n - i;
      if(j >= 0 && s[j] == '0') {
        n = j;
        ans.push_back(i);
        break;
      }
    }
  }
  reverse(all(ans));
  for(auto v : ans) cout << v << ' ';
  cout << endl;
}