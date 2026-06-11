#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{
    int N,M;
    cin >> N >> M;
    vi S(N),T(M);
    in(N,S);in(M,T);
    
    ve<vl> dp(N+1,vl(M+1,0));
    
    rep(i,N){
        reps(j,1,M+1){
            
            if(S[i] == T[j-1]){
                dp[i+1][j] = dp[i+1][j-1] + dp[i][j-1] + 1 + (mod+dp[i][j]-dp[i][j-1])%mod;
            }else{
                dp[i+1][j] = dp[i+1][j-1] + (mod+dp[i][j]-dp[i][j-1])%mod;
            }

            dp[i+1][j] %= mod;
        }
    }
    //outmat(dp);
    cout << (dp[N][M]+1)%mod << endl;
    

    
    
    
    

    return 0;
}
