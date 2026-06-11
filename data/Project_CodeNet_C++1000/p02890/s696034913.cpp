#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
#define ll long long                                    // long long省略
#define pb push_back                                    // push_back省略
#define fi first                                        // first省略
#define se second                                       // second省略
#define itn int                                         // int誤字保険
#define count cout                                      // cout誤字保険
#define vecotr vector                                   // vector誤字保険

#define rep(i,l,r)for(ll i=(l);i<(r);i++)               // 範囲[l, r)で刻み1のfor文(順方向)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))         // 範囲[l, r)で刻みkのfor文(順方向)
#define rrep(i,l,r)for(ll i=(r-1);i>=(l);i--)           // 範囲[l, r)で刻み1のfor文(逆方向)
#define rrepp(i,l,r,k)for(ll i=(r-1);i>=(l);i-=(k))     // 範囲[l, r)で刻みkのfor文(逆方向)
#define all(x) (x).begin(), (x).end()                   // vectorのポインタ位置指定用
#define max(p,q)((p)>(q)?(p):(q))                       // max拡張
#define min(p,q)((p)<(q)?(p):(q))                       // min拡張
#define bit(n,m)(((n)>>(m))&1)                          // 変数nのm番目のbitを取り出す
/*
   upll : (a<b)なら-1, (a=b)なら0, (a>b)なら1
 downll : (a<b)なら1, (a=b)なら0, (a>b)なら-1

 const void* a : 型を縛らずにconstをつける(=変数aが読み込み専用の変数であることを明示する)
        (ll*)a : 変数aがconst long long *型であると明示する
*/
// int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
// int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
// void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
// void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

#define INF ((1LL<<62)-(1LL<<31))
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p) pom(a,p-2,p)

vector<ll> tmp(3*100000+1,0);
vector<ll> cnt(3*100000+1,0);
vector<pair<ll,ll>> p;

bool Compare(ll k, ll m){
    ll sum = 0;
    rep(i,0,p.size()) sum += min(p[i].fi, m) * p[i].se;
    return sum >= k*m;
}

int main(){
    ll n; cin >> n;
    
    // 枚数をカウント
    rep(i,0,n){ ll a; cin >> a; tmp[a]++; }

    // 同じ枚数のものが何種類あるかを管理
    rep(i,1,n+1) cnt[tmp[i]]++;

    // cntをpairで管理(0枚はいらないので切る)
    rep(i,1,n+1) if(cnt[i] != 0) p.pb(pair<ll,ll>(i, cnt[i]));

    rep(k, 1, n+1){
        //取り除ける回数を2分探索
        ll lb = 0, ub = (n/k)+1, mid;
        while(ub - lb > 1){
            mid = (lb + ub) / 2;
            if(Compare(k, mid)){
                lb = mid;
            }else{
                ub = mid;
            }
        }
      	cout << lb << endl;
    }
}