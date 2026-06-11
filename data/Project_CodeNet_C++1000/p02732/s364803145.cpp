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

    vector<ll> S(*max_element(all(A)) + 1);
    rep(i, n) S[A[i]]++;

    ll total = 0;
    rep(i, S.size()) {
        total += S[i] * (S[i] - 1) / 2;
    }

    rep(i, n) {
        ll m = S[A[i]];
        ll res = total - m * (m - 1) / 2 + (m-1) * (m - 2) / 2;
        put(res);
    }

}
signed main(){ Main();return 0;}