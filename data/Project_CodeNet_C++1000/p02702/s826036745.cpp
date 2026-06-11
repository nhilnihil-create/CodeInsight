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
    string S;
    cin >> S;

    reverse(all(S));

    ll pow10 = 1;
    vector<int> C(2020);
    C[0]++;
    ll v = 0;
    rep (i, S.size()) {
        v += pow10 * (S[i] - '0') % 2019;
        v = v % 2019;
        C[v]++;
        pow10 = ((pow10 * 10) % 2019);
    }

    ll res = 0;
    rep(i, C.size()) {
        res += C[i] * (C[i] - 1) / 2;
    }

    put(res);
}
signed main(){ Main();return 0;}