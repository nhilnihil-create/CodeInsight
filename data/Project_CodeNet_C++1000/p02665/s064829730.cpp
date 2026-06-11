#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    rep(i,a.size()) {
        cin >> a[i];
    }

    vector<ll> upper(n + 1,0);
    vector<ll> downer(n + 1,0);
    ll ucount = 0;
    ll dcount = 0;

    for(int i = a.size() - 1; i >= 0; i--) {
        ucount += a[i];
        dcount += a[i];
        upper[i] = ucount;
        downer[i] = dcount;
        dcount /= 2;
        if(downer[i] % 2 == 1 && i != 0) {
            dcount++;
            downer[i]++;
        }
    }

    if(downer[0] != 1) {
        cout << -1 << endl;
        return 0;
    }

    ll now = 1;
    ll ans = 0;

    rep(i, a.size()) {
        ans += now;
        now -= a[i];
        if(i != a.size()) {
            now = min(now * 2, upper[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}