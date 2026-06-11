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
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    int best = 1e8;    
    rep(i, n) {
        int sum0 = 0, sum1 = 0;
        rep(j, i) {
            sum0 += w[j];
        }
        rep (j, n - i) {
            sum1 += w[n - j - 1];
        }
        if (abs(best) > abs(sum1 - sum0)) {
            best = abs(sum1 - sum0);
        }
    }

    cout << best << endl;

    return 0;
}