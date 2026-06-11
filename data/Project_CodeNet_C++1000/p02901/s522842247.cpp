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

vector<int> a(1e+3+1),b(1e+3+1),c(1e+3+1,0);
auto dp=make_vec<int>(1e+3+1,pow(2,12));

int main(){
    int N,M;
    cin>>N>>M;
    
    int tmp;
    REP(i,M){
        cin>>a[i]>>b[i];
        REP(j,b[i]){
            cin>>tmp;
            tmp--;
            c[i]+=(1<<tmp);
        }
    }

    REP(i,M+1){
        REP(j,1<<N){
            if(j==0) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }
    int num;
    REP(i,M){
        REP(S,1<<N){
            dp[i+1][S]=min(dp[i][S],dp[i+1][S]); 
            dp[i+1][S|c[i]]=min(dp[i+1][S|c[i]],dp[i][S]+a[i]);       
            
        }
    }
    if(dp[M][(1<<N)-1]==INF) dp[M][(1<<N)-1]=-1;
    cout<<dp[M][(1<<N)-1]<<endl;

}