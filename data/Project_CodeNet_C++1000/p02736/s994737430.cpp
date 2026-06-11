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

int n;
vi a;

bool odd(int k) {
  bool res = false;
  rep(i, n) if(a[i] == k) res ^= (((n - 1) & i) == i);
  return res;
}

int main() {
  cin >> n;
  bool one = false;
  rep(i, n) {
    char c;
    cin >> c;
    a.push_back(c - '1');
    if(c == '2') one = true;
  }
  if(odd(1))
    cout << 1;
  else if(!one && odd(2))
    cout << 2;
  else
    cout << 0;
  cout << endl;
}