#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const ll MOD = 1e9+7;
signed main(){
    string s; cin >> s;
    ll dp[s.size()+1][13];
    rep(i,s.size()+1)rep(j,13)dp[i][j]=0;
    dp[0][0]=1;
    rep(i,s.size()){
        if(s[i]=='?'){
            rep(x,10){
                //dp[i+1][x]+=1;
                rep(j,13){
                    int y=(10*j+x)%13;
                    dp[i+1][y]+=dp[i][j];
                    dp[i+1][y]%=MOD;
                }
            }
        }else{
            int x=s[i]-'0';
            //dp[i+1][x]+=1;
            rep(j,13){
                int y=(10*j+x)%13;
                dp[i+1][y]+=dp[i][j];
                dp[i+1][y]%=MOD;
            }
        }
        //cout << dp[i+1][5] << endl;
    }
    cout << dp[s.size()][5] << endl;
    //int ret=0; for(int i=0;i<100;i++){if(i%13==5)ret++;} cout<<ret<<endl;
}
