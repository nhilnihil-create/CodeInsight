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

    ll res = 0;
    for (ll j= 1; j <= n; j++){
        // sum of (j, 2j, 3j, ..., [n/j]*j)
        ll m = n/j;
        res += j * m * (1 + m) / 2;
    }

    put(res);
}
signed main(){ Main();return 0;}