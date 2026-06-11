#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

using pdi = pair<ld, int>;

int main(){
    int N, n = 0;
    cin >> N;
    vector<ld> x, y;
    vector<pdi> p;
    rep(i, N){
        ld a, b;
        cin >> a >> b;
        if(a != 0 || b != 0){
            x.pb(a), y.pb(b);
            p.pb(pdi(atan2(b, a), n));
            n++;
        }
    }
    sort(all(p));
    ld ans = 0;
    rep(i, n){
        ld sumx = 0, sumy = 0;
        rep(j, n){
            int k = p[(i+j)%n].second;
            sumx += x[k], sumy += y[k];
            ans = max(ans, sumx*sumx + sumy*sumy);
        }
    }
    cout << sp(15) << sqrt(ans) << endl;
}