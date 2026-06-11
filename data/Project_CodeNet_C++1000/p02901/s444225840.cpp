#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N, M; cin >> N >> M;
    vector<int> A(M);
    vector<pair<int, ll>> keys;
    rep(i,M){
        int a, b; cin >> a >> b;
        int to = 0;
        rep(j,b){
            int c; cin >> c;
            c--;
            to |= 1 << c; 
        }
        keys.emplace_back(to, a);
    }

    vector<ll> dp(1<<N, INF);
    dp[0] = 0;

    rep(i,1<<N){
        rep(j,M){
            int to = i | keys[j].first;
            dp[to] = min(dp[to], dp[i]+keys[j].second);
        }
    }

    int ans = -1;
    if (dp.back() != INF) ans = dp.back();
    cout << ans << endl;
}