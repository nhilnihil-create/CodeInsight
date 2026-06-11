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
// xのn乗%modを計算
ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int N,K;
    cin >> N >> K;
    ll ans,tmp;
    ans=0;
    vector<ll> v(K+1,0);
    REP2(i,1,K+1){
        v[i]=mod_pow((ll)(K/i),N,(ll)MOD);
    }
    int next;
    REPD2(i,K,0){
        REP2(j,1,K+1){
            next=i+j*i;
            if(next<=K){
                if(v[i]<v[next]) v[i]+=MOD;
                v[i]-=v[next];
                v[i]%=MOD;
            }else{
                break;
            }
        }
    }

    REP2(i,1,K+1){
        ans+=((v[i]*i)%MOD);
        ans%=MOD;
    }


    cout << ans << endl;
    
}