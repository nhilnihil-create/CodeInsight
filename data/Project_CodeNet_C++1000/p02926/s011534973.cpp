#include "bits/stdc++.h"
using namespace std;
// #define int long long
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define INF 2e18;
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()
typedef long double f80;
 
int x[105], y[105];
 
signed main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fr(i, 1, n) {
        cin >> x[i] >> y[i];
    }
    f80 z = (2 * acos(-1))/1000000;
    ll ans = 0;
    for(int i = 0; i < 1000000; i++) {
        f80 x1 = cos(z * i), y1 = sin(z * i);
        int xx = 0, yy = 0;
        fr(j, 1, n) {
            if(x1 * x[j] + y1 * y[j] >= 0) {
                xx += x[j], yy += y[j];
            }
        }
        ans = max(ans, (ll)xx * xx + (ll)yy * yy);
    }
    cout << setprecision(20) << fixed << sqrtl(ans);
    return 0;
}