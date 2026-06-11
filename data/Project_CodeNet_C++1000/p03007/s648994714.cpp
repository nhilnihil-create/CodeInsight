#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<pair<int, int>> ans;
    int x = a[n - 1], y = a[0];
    reps(i, 1, n - 1) {
        if (a[i] < 0) {
            ans.emplace_back(x, a[i]);
            x -= a[i];
        }
        else {
            ans.emplace_back(y, a[i]);
            y -= a[i];
        }
    }
    ans.emplace_back(x, y);
    printf("%d\n", x - y);
    rep(i, sz(ans)) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}