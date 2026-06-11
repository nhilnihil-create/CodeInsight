#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
    
signed main(){
    speed;
    int x, y, n, m, k; cin >> x >> y >> n >> m >> k;
    vi r(n), g(m), c(k);
    rep(i, 0, n) cin >> r[i];
    rep(i, 0, m) cin >> g[i];
    rep(i, 0, k) cin >> c[i];
    int pos = x + y;
    int ans = 0;
    int cnt = 0;
    sort(all(r));
    sort(all(g));
    sort(all(c));
    vector<int> res;
    for(int i = n - 1; i > n - x - 1; i--) {
        ans += r[i];
        res.push_back(r[i]);
    }
    for(int i = m - 1; i > m - 1 - y; i--) {
        ans += g[i];
        res.push_back(g[i]);
    }
    sort(all(res));
    k--;
    for(int i = 0; i < res.size(); i++) {
        if(c[k] > res[i]) {
            ans += c[k] - res[i];
            k--;
        } else {
            break;
        }
        if(k < 0) break;
    }
    cout << ans;
    
    return 0;
}