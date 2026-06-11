#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    ll n, d;
    cin >> n >> d;

    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int c = 0;
    rep (i, n) {
        if (x[i] * x[i] + y[i] * y[i] <= d * d) {
c++;
        }
    }
    
    println(c)

    return 0;
}