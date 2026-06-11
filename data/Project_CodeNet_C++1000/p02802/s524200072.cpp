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
    int n, m; cin >> n >> m;
    int ac = 0, pe = 0;
    vector<int> ok(n + 1, 0);
    vector<int> wa(n + 1, 0);
    for(int i = 0, x; i < m; ++i){
        string s;
        cin >> x >> s; --x;
        if(!ok[x]){
            if(s == "AC"){
                ++ac;
                pe += wa[x];
                ok[x] = 1;
            }else{
                ++wa[x];
            }
        }
    }
    cout << ac << ' ' << pe << '\n';
    return 0;
}