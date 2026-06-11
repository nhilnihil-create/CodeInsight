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

const int max_a = 20005;

int main(){
    int H, N; cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vector<ll> dp(H+1, INF);
    dp[0] = 0;

    rep(i,N){
        rep(j, H+1){
            int nh = min(j + A[i], H);
            dp[nh] = min(dp[nh], dp[j]+B[i]);
        }        
    }
    
    cout << dp[H] << endl;
}
