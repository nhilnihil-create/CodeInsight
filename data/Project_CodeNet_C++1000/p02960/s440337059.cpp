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

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    string S;
    cin>>S;
    int N=S.size();
    auto dp=make_vec<ll>(N+1,13);

    REP(i,13){
        dp[0][i]=0;
    }
    dp[0][0]=1;

    REP(i,N){
        if(S[i]=='?'){
            REP(j,10){
                dp[i+1][j%13]+=dp[i][0];
                dp[i+1][(j+10)%13]+=dp[i][1];
                dp[i+1][(j+7)%13]+=dp[i][2];
                dp[i+1][(j+4)%13]+=dp[i][3];
                dp[i+1][(j+1)%13]+=dp[i][4];
                dp[i+1][(j+11)%13]+=dp[i][5];
                dp[i+1][(j+8)%13]+=dp[i][6];
                dp[i+1][(j+5)%13]+=dp[i][7];
                dp[i+1][(j+2)%13]+=dp[i][8];
                dp[i+1][(j+12)%13]+=dp[i][9];
                dp[i+1][(j+9)%13]+=dp[i][10];
                dp[i+1][(j+6)%13]+=dp[i][11];
                dp[i+1][(j+3)%13]+=dp[i][12];
            }
        }else{
            int j=S[i]-'0';
            dp[i+1][j%13]+=dp[i][0];
            dp[i+1][(j+10)%13]+=dp[i][1];
            dp[i+1][(j+7)%13]+=dp[i][2];
            dp[i+1][(j+4)%13]+=dp[i][3];
            dp[i+1][(j+1)%13]+=dp[i][4];
            dp[i+1][(j+11)%13]+=dp[i][5];
            dp[i+1][(j+8)%13]+=dp[i][6];
            dp[i+1][(j+5)%13]+=dp[i][7];
            dp[i+1][(j+2)%13]+=dp[i][8];
            dp[i+1][(j+12)%13]+=dp[i][9];
            dp[i+1][(j+9)%13]+=dp[i][10];
            dp[i+1][(j+6)%13]+=dp[i][11];
            dp[i+1][(j+3)%13]+=dp[i][12];
        }
        REP(j,13){
            dp[i+1][j]%=MOD;
        }
    }
    cout<<dp[N][5]<<endl;

}