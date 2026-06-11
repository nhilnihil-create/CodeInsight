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
    int N,K,C;
    string S;
    cin >> N >> K >> C;
    vector<int> L(K+2),R(K+2);
    cin >> S;
    L[0]=R[0]=-INF;
    L[K+1]=R[K+1]=INF;

    int cnt=1;
    REP(i,N){
        if(S[i]=='o'&&i>L[cnt-1]+C){
            L[cnt]=i;
            cnt++;
        }
        if(cnt>K) break;
    }
    cnt=0;
    REP(i,N){
        if(S[N-1-i]=='o'&&N-i-1<R[K-cnt+1]-C){
            R[K-cnt]=N-i-1;
            cnt++;
        }
        if(K-cnt<1) break;
    }
    
    REP2(i,1,K+1){
        if(R[i]==L[i]) cout << R[i]+1 << endl;
    }


    
}