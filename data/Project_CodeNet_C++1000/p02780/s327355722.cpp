#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

int main(){
    
    ll N, K; cin >> N >> K;
    vector<ll> p(N);
    rep(i,N) cin >> p[i];
    vector<ll> cum(N+1);
    rep(i,N){
        cum[i+1] = cum[i] + (p[i]+1);
    }
    ll mx = 0;
    rep(i,N){
        if (i+K > N) break;
        mx = max(mx, (cum[i+K] - cum[i]));
    }
    double ans = mx/2.0;
    //ans /= 2;
    printf("%.10f\n", ans);
}