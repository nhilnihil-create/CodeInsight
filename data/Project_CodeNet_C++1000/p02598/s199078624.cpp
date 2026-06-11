#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
// #define DEBUG 100
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll >;
 
const ll oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 2e6 + 100, maxm = 1e3+100;
const double PI = acos(-1);

ll solve(vector<ll> &vs, int n, ll k){
    ll a = 1, b = oo, best;

    while (a <= b){
        ll mid = (a + b) / 2, cnt = 0;
        for (auto it: vs) {
            cnt += (it/mid - (it%mid == 0? 1 : 0));
        }
        if (cnt > k){
            a = mid + 1;
        }
        else{
            best = mid;
            b = mid - 1;
        }
    }
    return best;
}
int main (){
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;

    vector<ll> vs(n);

    for (int i=0; i<n; i++){
        cin >> vs[i];
    }

    ll ans = solve(vs, n, k);

    cout << ans << endl;
    return 0;
}