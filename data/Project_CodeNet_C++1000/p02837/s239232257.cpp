#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> table(n);
    rep(i, n) {
        int a; cin >> a;
        rep(j, a) {
            int x, y; cin >> x >> y;
            table[i].push_back(make_pair(x-1, y));
        }
    }
    int ans = 0;
    rep(i, (1<<n)) {
        bool fl = true;
        rep(j, n) {
            if(!(i & (1<<j))) continue;
            for(pair<int, int> p : table[j]) {
                if((bool)((1<<p.first) & i) ^ p.second) {
                    fl = false;
                }
            }
        }
        if(fl) chmax(ans, (int)bitset<20>(i).count());
    }
    cout << ans << endl;
}