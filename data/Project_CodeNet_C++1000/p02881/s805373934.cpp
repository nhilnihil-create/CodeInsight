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
    ll n;
    cin >> n;

    ll best = 1e12;
    repi(i, sqrt(n) + 2) {
        if (n % i == 0) {
            best = min(best, i + n/i - 2);
        }
    }
    put(best);

    return 0;
}