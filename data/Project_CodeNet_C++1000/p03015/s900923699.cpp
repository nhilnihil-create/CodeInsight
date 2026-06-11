#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;

const ll M = 1000000007;
 
int main(){
    string L; cin >> L;
    ll n = sz(L);
    ll dp[n+1][2];
    dp[0][1] = 1;
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[1][1] = 1;
    rep(i, 2, n+1){
        if(L[i-1] == '0'){
            dp[i][0] = (dp[i-1][0])%M;
            dp[i][1] = (3*dp[i-1][1])%M;
        }else{
            dp[i][0] = (2*dp[i-1][0])%M;
            dp[i][1] = (3*dp[i-1][1] + dp[i-1][0])%M;
        }
    }
    ll g = 1;
    if(L[n-1] == '1'){
        g = 2;
    }
    prtl(((dp[n][1])+(dp[n-1][0]*g))%M);
}