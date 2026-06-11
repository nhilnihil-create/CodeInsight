#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

//ll dp[600][600];
ll dp[2][2000001];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(m);
    rep(i, m) cin >> b[i];
    
    vector<ll> Sa(n + 1);
    vector<ll> Sb(m + 1);
    rep(i, n) Sa[i + 1] = Sa[i] + a[i];
    rep(j, m) Sb[j + 1] = Sb[j] + b[j];

    int curJ = m;
    int best = 0;
    rep (i, n + 1) {
        ll rem = k - Sa[i];
        while (curJ >= 0) {
            if (Sb[curJ] <= rem) {
                best = max(i + curJ, best);
                break;
            }
            curJ--;
        }
    }

    put(best);

    return 0;
}