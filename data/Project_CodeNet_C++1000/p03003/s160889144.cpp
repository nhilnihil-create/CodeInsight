//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

//グローバル変数


//ライブラリ挿入


int main(){
    int N,M;
    cin>>N>>M;
    vector<int> S(1e5+10),T(1e5+10);
    REP(i,N) cin >> S[i];
    REP(i,M) cin >> T[i];
    vector<vector<ll>> dp(2010,vector<ll>(2010,0));
    vector<vector<ll>> sum(2010,vector<ll>(2010,0));
    dp[0][0]=1;
    sum[1][1]=1;
    REP(i,N+1){
        REP(j,M+1){
            if(i==0&&j==0) continue;
            if(i-1>=0&&j-1>=0&&S[i-1]==T[j-1]){
                dp[i][j] = sum[i][j];
            }
            sum[i+1][j+1]=(sum[i][j+1]%MOD+sum[i+1][j]%MOD-sum[i][j]%MOD+dp[i][j]%MOD);
            while(sum[i+1][j+1]<0){
                sum[i+1][j+1]+=MOD;
            }
            sum[i+1][j+1]%=MOD;
        }
    }

    cout <<sum[N+1][M+1] << endl;
    
    
}