#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    // ABC169-C, 
    /*ll a; double b; ll c; cin >> a >> b;
    c = round(b * ll(100));
    cout << a * c / ll(100) << endl;
    */
    
    // ABC169-B
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    if (a[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    ll limit = 1e18;
    rep(i, n) {
        if (limit / a[i] < ans || limit < ans * a[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans = ans * a[i];
    }
    cout << ans << endl;
    return 0;
}