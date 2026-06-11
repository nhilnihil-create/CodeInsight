#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> d(1000005);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int x : a) {
      if (d[x] != 0) {
        d[x]++;
        continue;
      }
      for (int j = x; j <= 1000000; j += x) {
        d[j]++;
      }
    }
    for (int x : a) {
      if (d[x] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}