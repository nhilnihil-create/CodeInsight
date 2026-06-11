#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll n;
    cin >> n;
    
    string S;
    cin >> S;

    vector<int> RGB[3];
    rep(i, n) {
        if (S[i] == 'R') {
            RGB[0].push_back(i);
        }
        if (S[i] == 'G') {
            RGB[1].push_back(i);
        }
        if (S[i] == 'B') {
            RGB[2].push_back(i);
        }
    }

    ll res = 0;
    rep (ir, RGB[0].size()) {
        ll r = RGB[0][ir];
        rep (ig, RGB[1].size()) {
            ll g = RGB[1][ig];
            ll a = min(g, r);
            ll b = max(g, r);
            vector<ll> invalid = {
                b + (b - a),
                a - (b - a),
            };
            ll mid = (a + b) / 2;
            if (b - mid == mid - a) {
                invalid.push_back(mid);
            }

            ll nB = RGB[2].size();
            for (auto ng: invalid) {
                auto it = lower_bound(all(RGB[2]), ng);
                if (it != RGB[2].end() && *it == ng) {
                    nB--;
                }
            }

            res += nB;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}