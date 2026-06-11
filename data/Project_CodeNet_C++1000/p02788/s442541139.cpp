#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, D, A;
    cin >> N >> D >> A;

    vector<p> k(N);
    vector<ll> s(N);

    ll S = 0;

    for(int i = 0; i < N; i++) {
        ll X, H;
        cin >> X >> H;
        k[i] = make_pair(X, H);
    }

    sort(k.begin(), k.end());

    vector<ll> x(N);
    vector<ll> h(N);

    for(int i = 0; i < N; i++) {
        x[i] = k[i].first;
        h[i] = k[i].second;
    }

    ll ans = 0;

    for(int i = 0; i < N; i++) {
        h[i] -= S;
        if(h[i] > 0) {
            ll a = h[i] / A;
            if(a * A < h[i]) {
                a++;
            }
            ans += a;
            S += a * A;
            ll pos = upper_bound(x.begin(), x.end(), x[i] + 2 * D) - x.begin() - 1;
            s[pos] += a * A;
        }
        S -= s[i];
    }

    cout << ans << endl;
}