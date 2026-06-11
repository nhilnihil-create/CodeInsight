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
    string l;
    cin >> l;
    //reverse(ALL(l));
    ll dp[2][l.length()+2];
    REP(i,2)REP(j,l.length()+2)dp[i][j]=0;
    dp[0][0]=1;
    dp[1][0]=2;
    FOR(i,1,l.length()){
        if(l[i]=='1'){
            dp[1][i]=dp[1][i-1]*2%MOD;
            dp[0][i]=dp[0][i-1]*3%MOD;
            dp[0][i]=(dp[0][i]+dp[1][i-1])%MOD;
        }else{
            dp[1][i]=dp[1][i-1];
            dp[0][i]=(dp[0][i-1]*3)%MOD;
        }
    }
    /*REP(i,2){
        REP(j,l.length()){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/


    cout << (dp[0][l.length()-1]+dp[1][l.length()-1])%MOD << endl;
    return 0;
}