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
    string l;cin>>l;
    int s=l.size();
    vvll dp(s+1,vll(2));
    dp[0][0]=(ll)1;
    //a,bを二進数表記したとき各桁がともに1でなければok→3通り
    rep(i,s){
        dp[i+1][1]+=dp[i][1]*3;
        if(l[i]=='1'){
            dp[i+1][1]+=dp[i][0];//a,bのi+1桁目が共に0
            dp[i+1][0]+=dp[i][0]*2;//a,bのi+1桁目が異なる
        }
        else dp[i+1][0]+=dp[i][0];//a,bのi+1桁目が共に0
        rep(j,2)dp[i+1][j]%=inf;
    }
    cout<<(dp[s][0]+dp[s][1])%inf<<endl;
}