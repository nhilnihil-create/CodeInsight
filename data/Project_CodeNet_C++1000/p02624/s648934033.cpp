#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n+1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        cnt[j]++;
      } 
      ans += (ll)i*cnt[i];
    } 
    cout << ans << endl;
    return 0;
}