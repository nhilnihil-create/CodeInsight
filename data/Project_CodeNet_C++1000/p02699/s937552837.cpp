#include <bits/stdc++.h>
using namespace std;
#define REP(name, stop) for (ll(name) = 0; (name) < (stop); (name)++)
using ll = long long;
using vi = vector<ll>;

int main(void) {
    ll S, W;
    cin >> S >> W;
    string ans;
    if (S > W)
        ans = "safe";
    else
        ans = "unsafe";
    cout << ans << endl;
    return 0;
}
