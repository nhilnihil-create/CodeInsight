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
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    REP(i,N) cin>>A[i];
    vector<ll> S(N+1);
    S[0]=0;
    map<ll,vector<ll>> mp;
    mp[0].push_back(0);
    ll tmp;
    REP(i,N){
        S[i+1]=S[i]+A[i];
        tmp=(S[i+1]-(i+1))%K;
        if(tmp<0) tmp+=K;
        mp[tmp].push_back(i+1);
    }
    ll ans=0;
    ll num;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        vector<ll> t=itr->second;
        REP(i,t.size()){
            ll n =lower_bound(t.begin(),t.end(),t[i]+K)-upper_bound(t.begin(),t.end(),t[i]);
            ans+=n;
        }
    }
    cout<<ans<<endl;
}