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

signed main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int allgcd = 0;
    rep(i,n) allgcd = gcd(a[i], allgcd);
    
    const int LIMIT = 1000000;
    vector<vector<int>> p(LIMIT + 1);
    reps(i,2,LIMIT){
        if(!p[i].empty()) continue;
        for(int j = i; j <= LIMIT; j += i){
            p[j].push_back(i);
        }
    }
    
    vector<bool> has_prime(LIMIT+1, false);
    bool is_pairwise = true;
    
    rep(i,n){
        for(int pr : p[a[i]]){
            if(has_prime[pr]){
                is_pairwise = false;
            }else{
                has_prime[pr] = true;
            }
        }
        if(!is_pairwise) break;
    }
    
    if(is_pairwise){
        cout << "pairwise coprime" << endl;
    }else if(allgcd == 1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
}