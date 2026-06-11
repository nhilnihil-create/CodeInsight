#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> s;
  vector<int> ord(n + 1, -1);
  int c = 1, l = 0, v = 1;
  while(ord[v] == -1) {
    ord[v] = s.size();
    s.push_back(v);
    v = a[v - 1];
  }
  c = s.size() - ord[v];
  l = ord[v];

  if(k < l)
    cout << s[k];
  else {
    k -= l;
    k %= c;
    cout << s[l + k];
  }
}
