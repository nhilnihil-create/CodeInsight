#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;



int main()
{
    int N,M;
    cin >> N >> M;
    vl S(N);in(N,S);
    vl T(M);in(M,T);
    
    ve<ve<ll>> dp(N,ve<ll>(M,0));
    rep(i,M){
        if(i == 0){
            if(S[0] == T[0]) dp[0][0] = 1;
            continue;
        }
        
        if(S[0] == T[i]) dp[0][i] = dp[0][i-1]+1;
        else dp[0][i] = dp[0][i-1];
    }
    
    reps(i,1,N){
        if(S[i] == T[0]) dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = dp[i-1][0];
        dp[i][0] %= mod;
        reps(j,1,M){
            if(S[i] == T[j]) dp[i][j] = dp[i-1][j] + dp[i][j-1] + 1;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod + mod - dp[i-1][j-1];
            dp[i][j] %= mod;
        }
        
    }

    out((dp[N-1][M-1]+1)%mod);

    /*
    rep(i,N){
        rep(j,M) cout << dp[i][j] << " ";
        cout << endl;
    }
     */

    return 0;
}
