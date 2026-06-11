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
ll M = 1000000007;

int main(){
    ll N, T; cin >> N >> T;
    vll A(N+1), B(N+1);
    rep(i, 1, N+1){
        cin >> A[i] >> B[i];
    }
    vvll dp(N+1, vll(T+1));
    rep(i, 0, T+1){
        dp[0][i] = 0;
    }
    rep(i, 1, N+1){
        rep(j, 0, T){
            if(j < A[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]]+B[i]);
            }
        }
    }
    vvll dpp(N+1, vll(T+1));
    rep(i, 0, T){
        dpp[0][i] = 0;
    }
    reverse(all(A)); reverse(all(B));
    rep(i, 1, N+1){
        //prt(A[i-1]); prt(" ");
        rep(j, 0, T){
            if(j < A[i-1]){
                dpp[i][j] = dpp[i-1][j];
            }else{
                dpp[i][j] = max(dpp[i-1][j], dpp[i-1][j-A[i-1]]+B[i-1]);
            }
        }
    }
    //prt(endl);
    reverse(all(A)); reverse(all(B));
    ll x = 0;
    rep(i, 1, N+1){
        ll mx = 0;
        rep(j, 0, T){
            ll a = dp[i-1][j];
            ll b = dpp[N-i][T-1-j];
            chmax(mx, a+b);
        }
        chmax(x, mx+B[i]);
    }
    prtl(x);
    return 0;
}

