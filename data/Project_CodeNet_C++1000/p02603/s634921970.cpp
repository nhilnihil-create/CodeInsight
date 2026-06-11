#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i, a, b) for(int i = int(a); i < int(b); i++)
#define rnr(i, a, b) for(int i = int(a); i >= int(b); i--)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int n; cin >> n;
    ll a[n]; rep(i, n) cin >> a[i];
    //he have 1000 [yen]
    int minv_i = 0, minv = a[0];
    vector<Pint> ans;
    for(int i = 1; i < n; ++i) {
        if(minv < a[i]) {
            ans.pb(mp(minv_i, i));
        }
        minv = a[i];
        minv_i = i;
    }
    ll money = 1000;
    for(auto i : ans) {
        ll numStock = money / a[i.first];
        money -= numStock * a[i.first];
        money += numStock * a[i.second];
    }
    cout << money << endl;
}
