#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

vector<int> aisle[100001];

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    aisle[a - 1].push_back(b - 1);
    aisle[b - 1].push_back(a - 1);
  }

  int ans = 0;
  rep(i, n) {
    bool good = true;
    for(int m : aisle[i]) {
      if(h[i] <= h[m]) {
        good = false;
        break;
      }
    }
    if(good)
      ans++;
  }

  cout << ans;
}
