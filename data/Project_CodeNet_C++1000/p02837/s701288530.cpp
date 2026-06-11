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
signed main()
{
    int n;
    cin >> n;

    vector<vector<int> > xs;
    vector<vector<int> > ys;
    rep (i, n) {
        int a;
        cin >> a;
        vector<int> x(a), y(a);
        rep(i, a) cin >> x[i] >> y[i];
        xs.push_back(x);
        ys.push_back(y);
    }

    int best = 0;
    rep (pat, 1 << n) {
        vector<int> p(n);
        rep(i, n) p[i] = 1 - (int)((pat >> i) & 1);
        bool ok = true;
        rep(i, n) {
            if (p[i] >= 1) {
                // 正直と仮定
                const auto& x = xs[i];
                const auto& y = ys[i];
                rep (j, x.size()) {
                    if (p[x[j] - 1] != y[j]) {
                        // 矛盾
                        ok = false;
                        break;
                    }
                }
            }
            if (ok == false){
                break;
            }
        }

        if (ok) {
            int cnt = 0;
            rep(i, n) {
                if (p[i]) { cnt++; }
            }
            best = max(best, cnt);
        }
    }

    put(best);

    return 0;
}