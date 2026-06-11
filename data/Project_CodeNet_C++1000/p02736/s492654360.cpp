#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>

#define x1 x1228
#define y1 y1228

#define left left228
#define right right228

#define pb push_back
#define eb emplace_back

#define mp make_pair                                                                
                                                                                                                                        
#define ff first                                                                  
#define ss second   

#define matr vector<vector<int> > 

#define all(x) x.begin(), x.end()


using namespace std;
typedef long long ll; 
typedef long double ld; 
                                                                                                   
const int maxn = 3e5 + 7, mod = 1e9 + 7, MAXN = 1e6 + 7;
const double eps = 1e-9;
const ll inf = 1e18;
mt19937 rnd(time(0));
int n;
string s; 
int binom[2][2]; 

int cnk(int n, int k) {
    int ans = 1; 
    for (int i = 0; i < 30; ++i) {
        ans *= binom[(n >> i) & 1][(k >> i) & 1]; 
    }
    return ans; 
}

bool check(vector<int> cur) {
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] == 1) return false; 
    }
    for (auto &v : cur) {
        if (v == 2) v = 1; 
    }
    int res = 0; 
    /*
    for (auto v : cur) cout << v << " "; 
    cout << endl; 
    cout << "binom: "; 
    */
    for (int i = 0; i < (int)cur.size(); ++i) {
//        cout << cnk((int)cur.size() - 1, i) << " "; 
        res ^= cnk((int)cur.size() - 1, i) * cur[i]; 
    }
//    cout << endl; 
    return (res == 1); 
}

void solve() {
    cin >> n >> s; 
    vector<int> cur; 
    for (auto v : s) cur.pb(v - 'a'); 
    for (int i = 0; i < 1; ++i) {
        vector<int> t;         
        for (int j = 1; j < cur.size(); ++j) t.pb(abs(cur[j - 1] - cur[j])); 
        cur = t; 
    } 
    if (check(cur)) {
        cout << 2; 
        return; 
    } 
    for (auto &v : cur) {
        if (v == 2) v = 0; 
        else if (v == 1) v = 2; 
    }    
    if (check(cur)) {                 
        cout << 1; 
        return; 
    }
    cout << 0; 
}                                
   
signed main() {
#ifdef LOCAL
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else 
    
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    binom[0][0] = 1; 
    binom[1][0] = 1; 
    binom[1][1] = 1;
    int t = 1; 
    for (int i = 0; i < t; ++i) {              
        solve();
    }
    return 0;
}  