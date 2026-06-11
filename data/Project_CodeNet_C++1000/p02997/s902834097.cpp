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
    ll N, K; cin >> N >> K;
    if(K > (N-1)*(N-2)/2){
        prtl(-1);
        return 0;
    } 
    if(K == 0){
        vector<P> ans(0);
        rep(i, 2, N+1){
            rep(j, 1, i){
                ans.emplace_back(mp(i, j));
            }
        }
        prtl(sz(ans));
        for(auto x: ans){
            prt(x.first); prt(" "); prtl(x.second);
        }
        return 0;
    }
    ll n = 0;
    bool t = true;
    while(t){
        ll c = n*(n-1)/2;
        n++;
        ll d = n*(n-1)/2;
        if(c < K&&d >= K){
            t = false;
        }
    }
    ll r = n*(n-1)/2 - K;
    vector<P> ans(0);
    rep(i, 0, n){
        ans.emplace_back(mp(1, i+2));
    }
    rep(i, 0, r){
        ans.emplace_back(mp(i+2, i+3));
    }
    rep(i, n+2, N+1){
        rep(j, 1, i){
            ans.emplace_back(mp(i, j));
        }
    }
    prtl(sz(ans));
    for(auto x: ans){
        prt(x.first); prt(" "); prtl(x.second);
    }
}


    



