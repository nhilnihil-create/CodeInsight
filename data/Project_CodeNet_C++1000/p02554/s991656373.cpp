#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using pint = pair<int, int>; 
using pll  = pair<ll, ll>;
using vint = vector<int>; 
using vll  = vector<ll>;
using vstr = vector<string>;

//　定数, 変数 *********************************************
const ll MOD=1e9+7;
const ll INF=1ll<<60;

int N;
// *********************************************************
int main(){

    cin >> N ;

    ll w=1;
    rep(i,N){
        w=w*10%MOD;
    }
    //cout << w<<endl;
    

    ll t=1;
    rep(i,N){
        t = t*9% MOD;
    }
    //cout << t <<endl;
    
    ll s=1;
    rep(i,N){
        s=s*8%MOD;
    }

    ll ans= (w-t-t+s)%MOD;
    ans = (ans+MOD)%MOD;
    cout << ans;

    return 0;
}