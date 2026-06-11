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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = 0, r = 10e9;
    while (l+1 < r) {
      ll mid = (l+r)/2;
      ll cnt = 0;
      rep(i,n) {
        cnt += (a[i]-1)/mid;
      }
      if (cnt <= k) r = mid;
      else l = mid;
    }
    cout << r << endl;
    return 0;
}