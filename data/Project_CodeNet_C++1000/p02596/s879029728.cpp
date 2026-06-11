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
    int k;
    cin >> k;
    int v = 7;
    rep (i, k) {
        if (v % k == 0) {
            put(i+1);
            return 0;
        }
        v = (10 * v + 7) % k;
    }
    put(-1)
    return 0;
}