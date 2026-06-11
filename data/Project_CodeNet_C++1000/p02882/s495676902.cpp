#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

vector<ll> divisor(ll N) {
    vector<ll> RES;
    for (ll I = 1; I*I <= N; I++) {
        if (N%I == 0) {
            RES.push_back(I);
            if (I != N/I) RES.push_back(N/I);
        }
    }
    return RES;
}

int main() {
    int a,b,x; cin >> a >> b >> x;
    double pi = 2.0 * asin(1.0); 
    double unit_r = 180.0 / pi;
    if (a*a*b < 2*x) {
        double kata = (double) (a*a*b-x)*2/(a*a*a);
        double ans = atan(kata) * unit_r;
        cout << setprecision(15) << ans << endl;

    } else {
        double kata = (double) a*b*b/(2*x);
        double ans = atan(kata) * unit_r;
        cout << setprecision(15) << ans << endl;
    }
    return 0;
}