#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int n;
cin >> n;
map<string,int> m;
rep(i,n) {
  string a;
  cin >> a;
  sort(a.begin(),a.end());
  m[a]++;
}
ll ans = 0;
for (auto p: m) {
  ll s = p.second;
  ans += s * (s-1) /2;
}

cout << ans << endl;

return 0;
}

