#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll a, b, x;
    cin >> a >> b >> x;

    ld theta = 0;
    if(2 * x < a * a * b) {
        ld tan = (ld)a * b * b / (2 * x); 
        theta = atanl(tan);
    }
    else {
        ld tan = (ld)(2 * a * a * b - 2 * x) / (a * a * a);
        theta = atanl(tan);
    }

    ld rad = theta / M_PI * 180;
    printf("%.10Lf\n", rad);

}
signed main(){ Main();return 0;}