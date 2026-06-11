#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const double PI = acos(-1);


int main(){
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double p = (60*h + m) % 720;
    double q = m;

    double diff = abs(p * PI / 360 - q * PI / 30);
    diff = min(2*PI - diff, diff);
    
    double ans = a*a + b*b - 2*a*b*cos(diff);

    cout << fixed << setprecision(20) << pow(ans, 0.5) << endl;

    return 0;
}
