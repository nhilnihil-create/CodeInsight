#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    vector<int> a(9);
    rep(i, 9) cin >> a[i];
    
    int n;
    cin >> n;

    vector<int> b(n);
    rep(i, n) cin >> b[i];
    
    bool c[9];
    rep(i, 9) c[i] = false;
    rep(i, n) {
        rep(j, 9) {
            if (a[j] == b[i]) {
                c[j] = true;
            }
        }
    }

    rep(j, 3) {
        if (c[3 * j + 0] && c[3 * j + 1] && c[3 * j + 2]) {
            put("Yes")
            return 0;
        }
        if (c[0 + j] && c[3 + j] && c[6 + j]) {
            put("Yes")
            return 0;
        }
    }
    if (c[0] && c[4] && c[8]) {
        put("Yes");
        return 0;
    }
    if (c[2] && c[4] && c[6]) {
        put("Yes");
        return 0;
    }
        put("No");

    return 0;
}