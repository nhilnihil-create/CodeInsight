#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

//DPの中では簡単な問題_typical stair
int main(){
    ll N,M;
    cin >> N >> M;
    vector<bool> koware(N+1);
    koware.assign(N+1,true);

    for(ll i = 0;i < M;i++){
        ll a;
        cin >> a;
        koware.at(a) = false;
    }

    //DPで初期化
    vector<ll> dp(N+1,0);

    //初期条件
    dp[0] = 1;
    if(koware[1])
        dp[1] = 1;
    
    for(ll i = 2;i <= N;i++){
        if(koware.at(i-2))
            dp[i] += dp[i-2];
        if(koware.at(i-1))
            dp[i] += dp[i-1];
        dp[i] %= MOD;
    }

    cout << dp[N] << endl; 

    return 0;
}