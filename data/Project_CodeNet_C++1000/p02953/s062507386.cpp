#include <bits/stdc++.h>
#define ll long long int
#define ld long double
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
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ma = 0;
    rep(i, n) {
        if (ma - h[i] >= 2) {
            put("No");
            return 0;
        }
        ma = max(ma, h[i]);
    }
    
    put("Yes");

    return 0;
}