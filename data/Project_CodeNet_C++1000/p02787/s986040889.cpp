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
    ll H, N; cin >> H >> N;
    vll a(N), b(N);
    rep(i, 0, N){
        cin >> a[i] >> b[i];
    }    
    ll dp[H+10001];
    dp[H+10000] = 0;
    rrep(i, H+9999, -1){
        ll t = INF;
        rep(j, 0, N){
            if(i + a[j] > H + 10000){
                continue;
            }
            t = min(dp[i+a[j]] + b[j], t);
        }
        dp[i] = t;
    }
    ll k = INF;
    rep(i, 0, 10001){
        k = min(dp[i], k);
    }
    prt(k);
}



