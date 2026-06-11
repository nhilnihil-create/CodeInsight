#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define ff first
#define ss second
const ll mod =   1e9 +7  ;
ll multiply(ll a, ll b ){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void solve(){
    int n , m ;
    cin >> n >> m ;
    vector < string > grid(n) ;
    for( int i = 0 ; i < n ; i++) cin >> grid[i] ;
    vector < vector < int > > dp(n,vector<int>(m));
    if(grid[0][0]=='#') dp[0][0] = 1 ;
    for( int i = 1 ; i < m ; i++){
        dp[0][i] = dp[0][i-1];
        if(grid[0][i-1]=='.' && grid[0][i]=='#')
            dp[0][i]++;
    }
    for( int i = 1 ; i < n ; i++){
        dp[i][0] = dp[i-1][0] ;
        if(grid[i-1][0]=='.' && grid[i][0]=='#')
            dp[i][0]++;
    }
//    for( int i = 0 ; i < n ; i++) cout << dp[i][0] << " " ;
//    cout << '\n' ;
    for( int i = 1 ; i < n ; i++){
        for( int j = 1 ; j < m ; j++){
            int x = dp[i-1][j] + (grid[i][j]=='#' && grid[i-1][j]=='.'?1:0);
            int  y = dp[i][j-1] + (grid[i][j]=='#' && grid[i][j-1]=='.'?1:0);
            dp[i][j] = min(x,y);
        }
    }
//    for( int i = 0 ; i < n ; i++){
//        for( int j = 0 ; j < m ; j++){
//            cout << dp[i][j] << " " ;
//        }
//        cout << '\n' ;
//    }
    cout << dp[n-1][m-1] ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1 ;
    //cin >> t ;
    while(t--){
        solve( );
    }
}
