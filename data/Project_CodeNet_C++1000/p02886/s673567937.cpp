#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = m; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, n) cin >> d[i];
    ll sum = 0;
    
    rep2(i, 0, n -1) {
        rep2 (j, i + 1, n) {
            sum += d[i] * d[j];
        }
    }
    put(sum)

    return 0;
}