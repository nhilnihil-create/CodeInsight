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
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    
    int best = 1e8;
    repi(p, 101) {
        int sum = 0;
        rep(i, n) sum += (p - x[i]) * (p - x[i]);
        best = min(best, sum);
    }

    put(best);

    return 0;
}