#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, m;
    cin >> n >> m;
    dsu d(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d.merge(a,b);
    }
    int ans = 0;
    rep(i,n) if (d.leader(i) == i) ans++;
    ans--;
    cout << ans << endl;
    return 0;  
}