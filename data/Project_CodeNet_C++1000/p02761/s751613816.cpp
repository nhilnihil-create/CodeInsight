#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<char> c(m);
  rep(i,m) {
    cin >> s[i] >> c[i];
  }
  rep(i,1005) {
    string a = to_string(i);
    if(a.size() != n) continue;
    int j = 0;
    while(j < m) {
      if(a[s[j]-1] != c[j]) break;
      j++;
    }
    if(j != m) continue;
    cout << a << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}