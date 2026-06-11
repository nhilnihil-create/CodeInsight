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
    ll n, K;
    cin >> n >> K;

    string S;
    cin >> S;

    ll res = 0;

    ll baseHappy = 0;
    rep(i, n - 1) {
        if (S[i] == S[i+1]) baseHappy++;
    }

    put(min(baseHappy + 2 * K, n - 1));
}
signed main(){ Main();return 0;}