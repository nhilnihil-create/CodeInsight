#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<int> path[n];
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    int ans = 0;
    rep(i,n) {
        int highest = h[i];
        int highob = i;
        for(int x : path[i]) {
            if (h[x] >= highest) {
                highest = h[x];
                highob = x;
            }
        }
        if (highob == i) ans++;
    }
    cout << ans << endl;
    return 0;
}