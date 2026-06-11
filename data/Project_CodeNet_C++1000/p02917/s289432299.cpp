#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int n;
cin >> n;
vector<int> b(n-1);
rep(i,n-1) cin >> b[i];
ll ans = 0;
rep(i,n) {
  if (i == 0) ans += b[i];
  else if (i == n-1) ans += b[i-1];
  else ans += min(b[i],b[i-1]);
}
cout << ans << endl;
return 0;
}

