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
    int N;
    cin>>N;
    string S_ori;
    cin>>S_ori;
    int ans=0;
    REP(l,N){
        string S=S_ori.substr(l,S_ori.size());
        //Z-Algorithm
        vector<int> A(S.size(),0);
        A[0] = S.size();
        int i = 1, j = 0;
        while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
        }
        REP(i,S.size()){
            if(i>=A[i]) ans=max(ans,A[i]);
        }
    }
    cout<<ans<<endl;
    
}