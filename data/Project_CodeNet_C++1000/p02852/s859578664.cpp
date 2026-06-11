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
    ll n, m; cin >> n >> m;
    string S; cin >> S;
    vll p(0); ll cc = 1;
    rep(i, 1, n+1){
        if(S[i] == S[i-1]){
            cc++;
        }else{
            p.emplace_back(cc);
            cc = 1;
        }
    }
    p.emplace_back(cc);
    ll s = sz(p);
    bool b = false;
    rep(i, 0, s){
        if(i % 2 == 1){
            if(p[i] >= m){
                b = true;
            }
        }
    }
    vll cnt(n+1);
    ll k = 0;
    rep(i, 0, n+1){
        if(S[i] == '1'){
            cnt[i] = INF;
            k++;
        }else{
            cnt[i] = k;
            k = 0;
        }
    }
    for(auto x: cnt){
        //prtl(x);
    }
    if(b){
        prtl(-1);
        return 0;
    }
    vll dp(n+1, INF);
    dp[0] = 0;
    ll t = 0, c = 1, v = 0;
    rep(i, 1, n+1){
        if(S[i] == '1'){
            //prtl(dp[i]);
            continue;
        }
        if(i - t <= m){
            dp[i] = c;
            v = i;
        }else{
            c++;
            t = v;
            dp[i] = c;
            v = i;
        }
        //debug(t);
        //prtl(dp[i]);
    }
    vll ans(0);
    ll g = 1;
    rrep(i, n-1, -1){
        if(S[i] == '1'){
            //debug(i); debug(g);
            g++;
            continue;
        }
        if(g+cnt[i] < m){
            //debug(i); debug(g);
            g++;
        }else{
            //debug(i); debug(g);
            ans.emplace_back(g);
            g = 1;
        }
    }
    ans.emplace_back(g-1);
    reverse(all(ans));
    for(auto x: ans){
        if(x != 0){
            prt(x); prt(" ");
        }
    }
}

