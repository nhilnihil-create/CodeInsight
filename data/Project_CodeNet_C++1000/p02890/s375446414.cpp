#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n) {
        mp[a[i]]++;
    }
    vector<int> x;
    for (auto m: mp) {
        x.push_back(m.second);
    }
    sort(x.begin(), x.end());
    vector<int> sum;
    sum.push_back(0);
    rep(i, x.size()) {
        sum.push_back(sum.back() + x[i]);
    }
    for(int i=1; i<=n; i++) {
        ll l = 0;
        ll r = n+1;
        while (r-l>1) {
            ll now = (l+r)/2;
            auto it = upper_bound(x.begin(), x.end(), now);
            int v = it - x.begin();
            ll s = sum[v] + now*(x.end()-it);
            if (s>=i*now) l = now;
            else r = now;
        }
        cout << l << endl;
    }
    
    return 0;
}
