#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (a[i] == 0) {
            println(0);
            return 0;
        }
    }
    ll prod = 1;
    rep(i, n) {
        if (a[i] > (ll)1000000000000000000 / prod) {
            println(-1);
            return 0;
        }
        prod *= a[i];
    }
    println(prod);

    return 0;
}