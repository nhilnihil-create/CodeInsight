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

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    int ans=0;
    REP(i,N){
        if(i>=1&&S[i]=='L'&&S[i-1]=='L'){
            ans++;
        }else if(i<N-1&&S[i]=='R'&&S[i+1]=='R'){
            ans++;
        }
    }
    cout<<min(ans+2*K,N-1)<<endl;
    

   
}