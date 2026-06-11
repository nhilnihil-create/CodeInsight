#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

signed main(){
    io();
    ld n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i = 0; i < n; ++i){
        ll x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    ld sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ld x = v[i].first - v[j].first;
            ld y = v[i].second - v[j].second;
            ld add = sqrt((x*x)+(y*y));
            sum += add;
        }
    }
    cout << fixed << setprecision(9);
    cout << 2*sum/n << '\n';
    return 0;
}