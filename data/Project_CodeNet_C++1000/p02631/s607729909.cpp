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
    vector<int> a(n);
    int x = 0;
    rep(i,n) {
      cin >> a[i];
      x ^= a[i];
    }
    rep(i,n) {
      int ans = a[i] ^ x;
      printf("%d\n", ans);
    }
    return 0;
}