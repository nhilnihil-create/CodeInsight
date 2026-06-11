#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<P> v;
    rep(i, n) {
        int x, l;
        cin >> x >> l;
        v.push_back({x+l, x-l});
    }

    sort(v.begin(), v.end());

    int INF = 1001001001;
    int ans = 0, t = -INF;
    rep(i, n) {
        if(t <= v[i].second) {
            ans++;
            t = v[i].first;
        }
    } 

    cout << ans << endl;
    return 0;
}