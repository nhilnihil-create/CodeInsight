#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    unordered_map <string,ll> ump;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        sort(all(s));
        ++ump[s];
    }
    ll ans = 0;
    for(const auto & x : ump){
        ll val = x.second;
        ans += (val * (val - 1) / 2);
    }
    cout << ans << '\n';
    return 0;
}