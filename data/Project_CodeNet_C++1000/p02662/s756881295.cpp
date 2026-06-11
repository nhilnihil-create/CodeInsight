//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};
const in mod=998244353;


//a^n (mod)
in modpow(in a, in n, in mod) {
    in res = 1ll;
    while (n > 0ll) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n,s;
    cin>>n>>s;
    vector<in> a(n);
        rep(i,n) cin>>a.at(i);
    vector<vector<in>> dp(n+1,vector<in>(s+1,0));
    dp[0][0]=1;
    rep(i,n){
        rep(j,s+1){
            if(dp[i][j]==0) continue;
            dp[i+1][j]+=dp[i][j]*2;
            dp[i+1][j] %=mod;
            if(j+a[i]>=s+1) continue;
            dp[i+1][j+a[i]]+=dp[i][j];
            dp[i+1][j+a[i]] %=mod;
        }
    }
    cout<<dp[n][s]<<endl;
}/*
./problem.exe
*/