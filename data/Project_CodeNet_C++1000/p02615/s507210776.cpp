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
    reverse(all(A));

    ll res = A[0];
    int cnt = 1;
    for (ll i = 1; ; i++) {
        if (cnt >= n - 1) {
            break;
        }
        res += A[i];
        cnt++;
        if (cnt >= n - 1) {
            break;
        }
        res += A[i];
        cnt++;
        if (cnt >= n - 1) {
            break;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}