#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main() {
ll n;
cin >> n;
ll ans = 100000000000000000;
for (ll i = 1;i*i <= n;i++) {
  ll k;
  if (n % i == 0) {
    k = n/i;
    ans = min(ans,i+k-2);
  }
}
cout << ans << endl;


return 0;
}

