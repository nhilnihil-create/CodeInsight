#include <bits/stdc++.h>


using namespace std;

using ll = long long;

const ll INF = LONG_LONG_MAX / 2;


int main(void) {
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> red, green, white;
    red.push_back(-1);
    for (ll i = 0; i < A; i++) {
        ll a;
        cin >> a;
        red.push_back(a);
    }
    green.push_back(-1);
    for (ll i = 0; i < B; i++) {
        ll b;
        cin >> b;
        green.push_back(b);
    }
    white.push_back(-1);
    for (ll i = 0; i < C; i++) {
        ll c;
        cin >> c;
        white.push_back(c);
    }

    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(white.begin(), white.end());

    ll ans = 0;
    while (X > 0 || Y > 0) {
        ll ra, ga, wa;
        ra = *red.rbegin();
        ga = *green.rbegin();
        wa = *white.rbegin();

        if (ra > wa && X > 0) {
            ans += ra;
            X--;
            red.pop_back();
            continue;
        } else if (ga > wa && Y > 0) {
            ans += ga;
            Y--;
            green.pop_back();
            continue;
        }

        ll r_sacrifice, g_sacrifice;
        r_sacrifice = X > 0 ? *(red.rbegin() + X - 1) : INF;
        g_sacrifice = Y > 0 ? *(green.rbegin() + Y - 1) : INF;

        if (r_sacrifice > g_sacrifice) {
            // eat as green
            Y--;
        } else {
            // eat as red
            X--;
        }
        ans += wa;
        white.pop_back();
    }
    cout << ans << endl;
}
