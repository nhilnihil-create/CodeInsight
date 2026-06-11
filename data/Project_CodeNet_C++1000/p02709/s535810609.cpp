#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for(const auto& e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void yn(bool j){cout << (j ? "Yes" : "No") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> long long bcount(T1 v, T2 a){return upper_index(v, a) - lower_index(v, a);} 
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}

int main(){
    ll N; cin >> N;
    vector<P> a(N);
    rep(i, N){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    reverse(all(a));
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if (N < i + j + 1) continue;
            chmax(dp[i + 1][j], dp[i][j] + (a[i + j].second - i) * a[i + j].first);
            chmax(dp[i][j + 1], dp[i][j] + (N - j - a[i + j].second - 1) * a[i + j].first);
        }
    }
    ll ans = 0;
    // debug2(dp);
    rep(i, N){
        chmax(ans, dp[i][N - i]);
    }
    pt(ans);
}