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

    vector<ll> P(n);
    rep(i, n) cin >> P[i];
    vector<ll> C(n);
    rep(i, n) cin >> C[i];
    
    rep(i, n) P[i]--;

    ll res = -1e18;
    rep(start, n) {
        int cycleNum = 0;
        ll cycleSum = 0;
        int v = start;
        rep (i, K) {
            v = P[v];
            cycleNum++;
            cycleSum += C[v];
            if (v == start) {
                break;
            }
        }

        if (v != start || cycleSum <= 0) {
            //　ループしない
            ll val = 0;
            v = start;            
            rep (i, cycleNum) {
                v = P[v];
                val += C[v];
                res = max(res, val);
            }
            continue;
        }

        ll nLoop = K / cycleNum - 1;
        ll val = nLoop * cycleSum;
        ll step = nLoop * cycleNum;
        v = start;
        while (step < K) {
            v = P[v];
            val += C[v];
            res = max(res, val);
            step++;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}