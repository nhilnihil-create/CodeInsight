#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    int h[n];
    rep(i, n) cin >> h[i];

    int a, b;
    int cnt[n] = {0};
    rep(i, m) {
        cin >> a >> b;
        a--; b--;
        if (h[a] > h[b]) cnt[b] = 1;
        if (h[a] < h[b]) cnt[a] = 1;
        if (h[a] == h[b]) {
            cnt[a] = 1;
            cnt[b] = 1;
        }
    }
    int ans = 0;
    rep(i, n) {
        if (cnt[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}