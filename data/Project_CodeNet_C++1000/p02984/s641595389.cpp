#include <bits/stdc++.h>
// #include <atcoder/all>
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
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll sum = accumulate(all(A), 0LL);

    vector<ll> S(2 * n);
    S[0] = A[0];
    repi(i, S.size()) S[i] = S[i-1] + A[(i * 2) % n];

    rep(i, n) {
        int start = 0;
        if (i % 2 == 0) {
            start = i / 2;
        }
        else {
            start = (n + 1) / 2 + i / 2;
        }

        ll v = S[start + (n + 1) / 2 - 1] - (start - 1 >= 0 ? S[start - 1] : 0);
        ll M = 2 * v - sum;
        cout << M << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}
signed main(){ Main();return 0;}