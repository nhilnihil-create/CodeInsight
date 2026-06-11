#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef pair <ll ,ll> pll;
typedef pair <int ,int> pii;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define print(a) {for (auto iiiiiiiiii : a) cout << iiiiiiiiii << ' '; cout << '\n';}
#define fi first
#define se second
#define all(x) (x).begin() , (x).end()

ll next() {ll x; cin >> x; return x;}

const ll inf = 1e18 , mod = 998244353;
const int intf = 2e9 , maxn = 3e5;
const double PI = 3.141592653589 , eps = 1e-9;


void solve(){
    int n; cin >> n;
    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    ll mx = *max_element(all(a));
    a.erase(max_element(all(a)));
    ll mn = *min_element(all(a));
    a.erase(min_element(all(a)));

    vector <pii> ans;

    for (int i = 0; i < a.size(); i ++){
        if (a[i] >= 0){
            ans.eb(mn , a[i]);
            mn -= a[i];
        } else {
            ans.eb(mx , a[i]);
            mx -= a[i];
        }
    }
    ans.eb(mx , mn);
    mx -= mn;

    cout << mx << '\n';
    for (auto x : ans) cout << x.fi << ' ' << x.se << '\n';
}


int main()
{
    #ifdef HERE
        freopen("input.txt" , "r" , stdin);
    #else
        //freopen(".in" , "r" , stdin); freopen(".out" , "w" , stdout);
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.precision(20);
    #endif

    for (int t = 1; t--;) solve();

    #ifdef HERE
        cout << setprecision(3) << fixed << "\n\nRuntime: " << (long double)(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
/*

*/
