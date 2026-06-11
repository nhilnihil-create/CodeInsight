#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define M 1000000007

ll powll(ll x, ll y) {
    ll re=1;
    rep(i, y) {
        re = re * x % M;
    }
    return re;
}


int main() {

    int n,m;
    cin >> n>>m;

    vector<ll> step(n+1, 0);
    vector<bool> bstep(n+1, true);

    rep(i, m) {
        int x;
        cin >> x;
        bstep[x] = false;
    }

    step[0] = 1;
    if (bstep[1] == true) {
        step[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (bstep[i] == true) {
            step[i] = (step[i - 1] + step[i - 2] )% M;
        }
    }
    cout << step[n];

    return 0;
}