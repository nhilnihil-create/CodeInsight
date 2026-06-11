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
vector<int> enum_div(int n){
    vector<int> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    int n=0;
    REP(i,N){
        cin>>A[i];
        n+=A[i];
    }
    vector<int> enum_list=enum_div(n);
    enum_list.push_back(n);
    sort(enum_list.begin(),enum_list.end());
    int ans=1;
    REP(i,enum_list.size()){
        vector<int> plus(N),minus(N);
        vector<int> sum_plus(N+1),sum_minus(N+1);
        REP(j,N){
            plus[j]=A[j]%enum_list[i];
        }
        sort(plus.begin(),plus.end());
        REP(j,N){
            minus[j]=(enum_list[i]-plus[j])%enum_list[i];
        }
        sum_plus[0]=0;
        sum_minus[N]=0;

        REP2(j,1,N+1){
            sum_plus[j]=sum_plus[j-1]+plus[j-1];
            sum_minus[N-j]=sum_minus[N+1-j]+minus[N-j];
        }

        int cnt=0;
        REP(j,N){
            if(j==0) continue;
            if(sum_plus[j]==sum_minus[j]&&sum_plus[j]<=K){
                ans=max(ans,enum_list[i]);
            }
        }
    }
    cout<<ans<<endl;
    
}