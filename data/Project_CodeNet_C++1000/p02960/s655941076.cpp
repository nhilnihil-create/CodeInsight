#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define MOD 1000000007
typedef long long ll;
const char sp = ' ';


using namespace std;
ll dp[200000][13], di=1;
int main(void){
    
    string S;
    cin>>S;
    MEMSET(dp, 0);
    dp[S.size()][0]=1;
    rep(i, S.size()){
        ll th=S.size()-1-i;
        if(S[th]=='?'){
            rep(j, 13) rep(k, 10){
                dp[th][(di*k+j)%13]+=dp[th+1][j];
                dp[th][(di*k+j)%13]%=MOD;
            }
        }
        else{
            rep(j, 13){
                dp[th][(di*(S[th]-'0')+j)%13]+=dp[th+1][j];
                dp[th][(di*(S[th]-'0')+j)%13]%=MOD;
            }
        }
        di*=10;
        di%=13;
    }
    /*rep(i, S.size()+1){
        rep(j, 13) cout<<dp[i][j]<<"\t";
        cout<<endl;
    }*/
    cout<<dp[0][5]<<endl;
    return 0;
}
