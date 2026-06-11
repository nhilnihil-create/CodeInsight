#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,m;cin>>n>>m;
    vin s(n),t(m);
    rep(i,n)cin>>s[i];
    rep(i,m)cin>>t[i];
    vvll dp(n+1,vll(m+1));
    rep(i,n)rep(j,m){
        dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]-dp[i][j];
        if(s[i]==t[j])dp[i+1][j+1]+=dp[i][j]+(ll)1;
        dp[i+1][j+1]%=inf;
        if(dp[i+1][j+1]<0)dp[i+1][j+1]+=inf;
    }
    cout<<(dp[n][m]+(ll)1)%inf<<endl;//空文字列分追加
}