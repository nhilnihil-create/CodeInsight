#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


// main1.cppとほぼ同じ
int main() {
    int n; cin >> n;
    V<P<ll, ll> > v(n);
    for(int i = 0; i < n; i++){
        ll x, l; cin >> x >> l;
        v[i] = make_pair(x + l, x - l);
    }
    sort(ALL(v));

    ll ans = 0;
    ll pre = -1e9;
    for(int i = 0; i < n; i++){
        if(pre <= v[i].second){
            ans++;
            pre = v[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}
