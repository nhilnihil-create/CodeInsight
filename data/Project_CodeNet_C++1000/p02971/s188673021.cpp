#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
#define dup(x,y) (((x)+(y)-1)/(y)) // x/yの除算の切り上げ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007; //1000000007
const ld pi = acos(-1);
 
//xor演算
//a^b=b^a
//a^(b^c)=(a^b)^c
//a^a=0
//a+b=a^b + 2(a&b)
//(4a)^(4a+1)^(4a+2)^(4a+3)=0

//セグメント木
//全て添字で扱うこと
// segment_tree seg;
// seg.build(配列名, 単位元)で宣言
// seg.build(a,0)
struct segment_tree{
    ll n; //vの要素数
    ll m; //葉の数
    vector<ll> v; //セグ木本体．ただの配列を使う
    ll id_e; //単位元 区間の和なら0、区間の積なら1、最大値なら-1とか、最小値ならINF、最大公約数なら0
 
    //二項演算
    ll binary_op(ll a,ll b){
        return max(a,b);//処理 区間の和ならa+b、区間の積ならa*b、最大値ならmax(a,b)、最初値ならmin(a,b)、最大公約数ならgcd(a,b)
    }
 
    //初期化関数．数列と単位元を受け取って初期化
    void build(vector<ll> a,ll b){
        id_e = b;
        m = 1;
        while(m<(ll)a.size()) m*=2; //aの項数以上の2べきのうち最小のものを求める
        n = 2*m-1;
        v.resize(n);
        for (ll i=0; i<(ll)a.size(); i++) v[m-1+i]=a[i]; //葉(1段目)の値
        for (ll i=a.size(); i<m; i++) v[m-1+i]=id_e; //葉(1段目)の右端の0埋め
        for (ll i=m-2; i>=0; i--){ //2段目以降を順番に埋めていく
        v[i]=binary_op(v[2*i+1],v[2*i+2]);
        }
    }
 
    //ある項の値をbに書き換え
    void update(ll a,ll b) {
        a+=(m-1);
        v[a]=b; //葉(1段目)を書き換え
        while((a-1)/2 != a){ //2段目以降を順番に書き換え
            a=(a-1)/2;
            v[a]=binary_op(v[2*a+1],v[2*a+2]);
        }
    }
 
    //区間和の補助関数
    //cur:今見ている頂点の，配列vでの添字
    //[l, r]:v[cur]がカバーする区間
    ll seg_sub(ll a,ll b,ll cur,ll l,ll r){
        if(a<=l && r<=b) return v[cur]; //今見ている頂点のカバーする区間が，[a,b]に完全に収まっている場合
        if(r<a || b<l) return id_e; //今見ている頂点のカバーする区間が，[a,b]と全く被っていない場合
        return binary_op( //今見ている頂点のカバーする区間が，[a,b]と一部被っている場合
            seg_sub(a,b,2*cur+1,l,(l+r)/2),
            seg_sub(a,b,2*cur+2,(l+r)/2+1,r)
        );
    }
 
    //区間[a, b]の和
    //最上段の頂点から子へ再帰していく
    ll partial_sum(ll a,ll b){return seg_sub(a,b,0,0,m-1);}
    };
 
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    segment_tree seg;
    seg.build(a,0);
    rep(i,n){
        if(i==0){
            cout << seg.partial_sum(1,n-1) << endl;
            continue;
        }
        if(i==n-1){
            cout << seg.partial_sum(0,n-2) << endl;
            continue;
        }
        cout << max(seg.partial_sum(0,i-1),seg.partial_sum(i+1,n-1)) << endl;
    }

 
 
 
}