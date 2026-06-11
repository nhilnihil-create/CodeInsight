#include <bits/stdc++.h>
 
#define loop(i, n) for(ll i = 0; i < n; i++)
#define loop1(i, a, n) for(int i = a; i < n; i++)
#define PI 3.141592653589793238
#define bc __builtin_popcountll
#define pf push_front
#define pb push_back
#define rf pop_front
#define rb pop_back
#define fs first
#define sc second
#define mp make_pair
#define fi ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9 + 7;
const ll INF = 1e9;
inline ll pwr(ll base, ll n, ll m) {ll ans = 1;while( n > 0 ) {if ( n & 1 ) ans = (ans * base) % m; base = (base * base) % m; n>>=1;}return ans;}
 
bool cmp( pair< long double, long double > a, pair< long double, long double > b ) {
    if (a.fs >= 0 && b.fs < 0)
        return true;
    if (a.fs < 0 && b.fs >= 0)
        return false;
    if (a.fs == 0 && b.fs == 0) {
        if (a.sc >= 0 || b.sc >= 0)
            return a.sc > b.sc;
        return b.sc > a.sc;
    }

    ll det = (a.fs * b.sc) - (b.fs * a.sc);
    if( det != 0 )
        return det < 0;

    ll d1 = (a.fs * a.fs) + (a.sc * a.sc);
    ll d2 = (b.fs * b.fs) + (b.sc * b.sc);
    return d1 > d2;
}
 
int main() {
    fi;
 
    // #ifndef ONLINE_JUDGE
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // #endif

    int n;
    cin >> n;
    long double x, y;
    vector< pair<long double, long double> > vctrs;
 
    loop(i, n) {
        cin >> x >> y;
        vctrs.pb(mp(x, y));
    }
 
    sort(vctrs.begin(), vctrs.end(), cmp);
    long double ans = 0;
 
    loop(i, n) {
        long double x1 = 0, y1 = 0;
        int cnt = 1, j = i;
 
        while( cnt <= n) {
            x1 += vctrs[j].fs;
            y1 += vctrs[j].sc;
            ans = max(ans, (x1*x1) + (y1*y1));
            j = (j+1) % n;
            cnt++;
        }
 
    }
 
    cout << setprecision(30);
    cout << fixed;
    cout << sqrtl(ans);
 
 
    return 0;
}