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
    ll X;
    cin >> X;

    vector<ll> v5(1000);
    repi(i, 1000) {
        v5[i] = i * i * i * i * i;
        if (i >= 1 && v5[i] - v5[i - 1] > X) {
            break;
        }
    }

    rep(i, v5.size()) {
        rep(j, v5.size()) {
            if (v5[i] - v5[j] == X) {
                cout << i << " " << j << endl;
                return;
            }

            if (v5[i] + v5[j] == X) {
                cout << i << " " << -j << endl;
                return;
            }
        }
    }
}
signed main(){ Main();return 0;}