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
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    sort(all(A));

    ll maxA = *max_element(all(A));
    vector<int> S(maxA + 1);

    rep(i, n) {
        if (S[A[i]]) {
            continue;
        }
        for (ll x = 2 * A[i]; x < S.size(); x += A[i]) {
            S[x] = 1;
        }
    }

    ll res = 0;
    rep(i, n) {
        if (i + 1 < n && A[i] == A[i + 1]) {
            continue;
        }
        if (i - 1 >= 0 && A[i-1] == A[i]) {
            continue;
        }
        if (S[A[i]] == 0) {
            res += 1;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}