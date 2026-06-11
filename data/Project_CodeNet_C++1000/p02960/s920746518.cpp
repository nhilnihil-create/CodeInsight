#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    string s;
    cin >> s;
    vector<ll>index(100100);
    int dp[100100][13];
    index[0]=1;
    REP(i,100100-1){
        index[i+1] = index[i]*10%13;
    }
    REP(i,100100){
        REP(j,13){
            dp[i][j]=0;
        }
    }
    reverse(ALL(s));
    if(s[0]=='?'){
        REP(i,10){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][(int)(s[0]-'0')]=1;
    }

    FOR(i,1,s.length()){
        ll now_dig=index[i];
        if(s[i]=='?'){
            REP(j,10){
                REP(k,13){
                    if(dp[i-1][k]==0)continue;
                    ll n = (now_dig*(j)+k)%13;
                    dp[i][n]=(dp[i][n]+dp[i-1][k])%MOD;
                }
            }

        }else{
            REP(j,13){
                if(dp[i-1][j]==0)continue;
                ll n = (now_dig*((int)(s[i]-'0'))+j)%13;
                dp[i][n]=(dp[i][n]+dp[i-1][j])%MOD;
            }
        }
    }

    cout << dp[s.length()-1][5] << endl;
    return 0;
}