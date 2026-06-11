#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
using intmap = map<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
inline bool bit (ll b, ll i) { return b & (1 << i); }
inline ll ceiv (ll a, ll b) { return (a + b - 1) / b; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define debug(x) cerr << #x << ": " << x << '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main(){
    string s, t;
    cin >> s >> t;
    map<char, set<int>> index;
    rep(i, s.length()){
        index[s[i]].insert(i+1);
    }
    
    int loops = 0, now = 0;
    for(char c : t){
        if(index[c].empty()){
            cout << -1 << endl;
            exit(0);
        }
        auto it = index[c].upper_bound(now);
        if(it == index[c].end()){
            loops++;
            it = index[c].begin();
        }
        now = *it;
    }
    
    cout << loops * s.length() + now << endl;
}