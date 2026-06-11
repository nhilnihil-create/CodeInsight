#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

int main(){
    //1e0=1,1e1=10,1e2=9,1e3=12,1e4=3,1e5=4 以下ループ
    //i桁目までであまりj=:dp[i][j]
    vector<int> en(6);
    en[0]=1;en[1]=10;en[2]=9;en[3]=12;en[4]=3;en[5]=4;
    
    string s;cin >> s;
    int n=s.size();
    reverse(s.begin(),s.end());
    vector<vector<ll>> dp(n+1,vector<ll>(13,0));
    dp[0][0]=1;
    rep(i,n){
        //dp[i+1][]を作る
        rep(j,13){
            if(s[i]!='?'){
                //各々場所がずれるだけ
                //s[i]*en[i%6]だけずれる
                dp[i+1][(j+(s[i]-'0')*en[i%6])%13]=dp[i][j];
            }
            else{
                //s[i][(j-x*en[i%6])%13]を足してく
                rep(x,10){
                    dp[i+1][j]+=dp[i][((j-x*en[i%6])%13+13)%13];
                }
                dp[i+1][j]%=big;
            }
        }
    }
    dp[n][5]=(dp[n][5]%big+big)%big;
    cout << dp[n][5] << endl;
}