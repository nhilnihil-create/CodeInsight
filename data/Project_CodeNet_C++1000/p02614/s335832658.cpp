#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
 
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define all(c) (c).begin(), (c).end()
#define sz(x) ((int)(x).size())
 
 
template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}
 
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    for(int i = 0; i < v.size(); i++) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}
 
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
 
const ll MOD = 1e9 + 7; //998244353
constexpr ll INF = 1e18;
const int MX = 3010;

char grid[6][6];
int n, m, k;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m ; j++)
            cin >> grid[i][j];
    
    int ans = 0;

    for(int subrow = 0; subrow < (1 << n); subrow++){
        for(int subcol =  0;  subcol < (1 << m); subcol++){
            int bls = 0;
            for(int i = 0; i < n; i++){
                if(subrow & (1 << (n - 1 - i)))
                    continue;
                for(int j = 0; j < m; j++){
                    if(subcol & (1 << (m - 1 - j)))
                        continue;
                    bls += (grid[i][j] == '#' ? 1 : 0);
                }
            }
            ans += (bls == k ? 1 : 0);
        }
    }

    cout << ans << endl;

    return 0;
}