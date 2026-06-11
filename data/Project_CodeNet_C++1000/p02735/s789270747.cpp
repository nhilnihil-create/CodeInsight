// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"

const ll MOD = 1000000007;

char mat[103][103];
int dp[103][103];
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    int n, m;
    cin >> n >> m;
    rep(i, 1, 103) rep(j, 1, 103) dp[i][j] = 1e9;

    repp(i, 1, n) repp(j, 1, m) cin >> mat[i][j];
    rep(i, 1, 103){
        dp[i][1] = dp[i - 1][1] + (mat[i][1] == '#' && mat[i][1] != mat[i - 1][1]);
        dp[1][i] = dp[1][i - 1] + (mat[1][i] == '#' && mat[1][i] != mat[i][1 - 1]);
    }

    repp(i, 1, n) repp(j, 1, m){
        if(mat[i][j] == mat[i][j + 1]) dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
        else if(mat[i][j] == '#') dp[i][j + 1] = min(dp[i][j], dp[i][j + 1]);
        else dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
        if(mat[i][j] == mat[i + 1][j]) dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
        else if(mat[i][j] == '#') dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
        else dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
    }

    cout << dp[n][m];
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}