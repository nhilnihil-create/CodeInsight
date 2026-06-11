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

int S; // 1<=S<=2000
ll dp[2001];

// *********************************************************
ll solve(){

}

int main(){

    cin >> S;

    dp[0]=1;

    for(int i=1;i<S+1;++i){
        if(i<3){
            dp[i]=0;
        }else{
            dp[i]=(dp[i-1]+dp[i-3])%MOD;
        }
    }

    cout << dp[S]<<endl;



    return 0;
}