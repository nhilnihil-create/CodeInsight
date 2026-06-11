#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> to[105];

int main() {
    int n, k;
    cin >> n >> k;
    if (k > (n-2)*(n-1)/2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        to[1].push_back(i);
        to[i].push_back(1);
    }
    int c = (n-2)*(n-1)/2 - k;
    for (int i = 2; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (c == 0) break;
            to[i].push_back(j);
            to[j].push_back(i);
            c--;
        }
    }
    vector<P> ans;
    for (int i = 1; i <= n; i++) {
        for (int x : to[i]) {
            if (i < x) ans.emplace_back(i,x);
        }
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}