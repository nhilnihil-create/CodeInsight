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
    string s;cin>>s;
    int n=s.size();
    vvll dp(n,vll(13));//桁dp的な:i+1桁目の時点での13で割った余りがjとなる場合の数
    if(s[n-1]=='?')rep(i,10)dp[0][i]=1;
    else dp[0][s[n-1]-'0']=1;
    ll res=1;ll tmp;const ll c=13;
    rep2(i,1,n){
        res*=10;res%=c;
        if(s[n-1-i]!='?'){
            rep(j,13){
                tmp=j-((s[n-1-i]-'0')*res)%c;
                if(tmp<0)tmp+=c;
                dp[i][j]+=dp[i-1][tmp];
                dp[i][j]%=inf;
            }
        }
        else{
            rep(j,13)rep(k,10){
                tmp=j-(k*res)%c;
                if(tmp<0)tmp+=c;
                dp[i][j]+=dp[i-1][tmp];
                dp[i][j]%=inf;
            }
        }
    }
    cout<<dp[n-1][5]<<endl;
}