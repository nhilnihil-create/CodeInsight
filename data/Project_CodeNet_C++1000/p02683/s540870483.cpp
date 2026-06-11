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
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n), a(m * n);
    rep(i, n) {
        cin >> c[i];
        rep(j, m) cin >> a[i * m + j];
    }

    int best = 1e9;
    rep(pat, 1 << n) {
        int cost = 0;
        vector<int> u(m);
        rep (i, n) {
            if ((pat >> i) & 1) {
                cost += c[i];
                rep (j, m) {
                    u[j] += a[i * m + j];
                }
            }
        }
        bool ok = true;
        rep(j, m) {
            if (u[j] < x) {
                ok = false;
                break;
            }
        }
        if (ok) {
            best = min(best, cost);
        }
    }

    put((best == 1e9 ? -1 : best));

    return 0;
}