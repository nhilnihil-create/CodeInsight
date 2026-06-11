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
    ll n, K;
    cin >> n >> K;

    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    rep(i, n) A[i]--;
    
    vector<int> seen(n, -1);
    ll cur = 0;
    bool skipped = false;
    rep (i, K) {
        seen[cur] = i;
        cur = A[cur];
        if (skipped == false && seen[cur] >= 0) {
            ll loopLen = 1 + i - seen[cur];
            i += (K - i - 1) / loopLen * loopLen;
            skipped = true;
        }
    }

    put(1 + cur);
}
signed main(){ Main();return 0;}