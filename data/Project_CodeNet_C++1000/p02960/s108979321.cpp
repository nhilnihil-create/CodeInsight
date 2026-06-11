#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string s;cin>>s;
    vector<ll[13]> dp(s.size()+1);
    constexpr ll mod = 1e9+7;
    dp[0][0]=1;
    REP(i,s.size()){
        REP(j,13){
            if(s[i]!='?') (dp[i+1][(10*j+s[i]-'0')%13] += dp[i][j])%=mod;
            else REP(k,10){
                (dp[i+1][(10*j+k)%13] += dp[i][j])%=mod;
            }
        }
    }
    cout<<dp[s.size()][5]<<endl;
}
