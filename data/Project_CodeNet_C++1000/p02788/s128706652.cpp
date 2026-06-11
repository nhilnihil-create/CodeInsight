#include <bits/stdc++.h>
using namespace std;
//=====================================================
// マクロ定義部
//=====================================================

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(ll i = (a); i <= (b); ++i)
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define DEBUG_VARIABLE(variable) cout << #variable << ":" << variable << endl
#define INFTY 1000000000000000000 // 10^18
#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない
//=====================================================
// 型定義部
//=====================================================

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll>    ll_ll;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef vector< pair<ll, ll> > Vec_Pair;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0 ;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0 ;}
//===================================================
// 関数のプロトタイプ宣言・関数に必要な配列の宣言
//===================================================

template <class X> void printArray(X *array, ll);
template <class X> void printVector(vector<X> &v);
template <class X> void printDimention(vector< vector<X> > &dv);
template <class X> void printMap(X);
template <class X> void printVecPair(vector<X> &v);
void printDV_Pair(vector<vector<pair<ll, ll> > > &v);
void printSet(set<ll> &S);
// 繰返し自乗法
ll RepeatSquaring(ll a, ll index);
// 最大公約数
ll GCD(ll, ll);
// 最小公倍数
ll LCM(ll, ll);
// 割り算した時に余りが有る時だけ、+1の商を返す。
ll div_one(ll res, ll div);

//===================================================
// グローバル
//===================================================

const int MOD = 1000000007;
//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};    // dj
const int dy[4] = {-1, 0, 1, 0};    // di
static const int NIL = -1;

ll N, k, K, V, E;
typedef struct _monster{
    ll X, H;
    /*
    _monster(ll arg1, ll arg2){
        X = arg1;   H = arg1;
    }
    */
    bool operator< (const struct _monster arg) const {
        return X < arg.X;
    }
} Monster;

//===================================================
// 関数
//===================================================


//===================================================
// main 問題処理部
//===================================================
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll D, A;
    cin >> N >> D >> A;
    vector<Monster> M(N);
    rep(i, N){
        cin >> M[i].X >> M[i].H;
        M[i].H = (M[i].H + A - 1) / A;  // 体力を予め、爆発の回数に変更
    }
    sort(M.begin(), M.end());

    queue< pair<ll, ll> > blast; // 爆風を記録。内部の値はどこまで届くかの座標と威力 何回分か
    // vector< pair<ll, ll> > blast; // 爆風を記録。内部の値はどこまで届くかの座標と威力 何回分か。新しいのが先にくる
    // ll vs = 0;

    // シミュレーション開始
    ll ans = 0, cul_blast = 0;
    rep(i, N){
        bool alive = true;
        // 既存の爆発;
        while(!blast.empty()){
            ll_ll tmp = blast.front();
            if(tmp.first < M[i].X){    // 爆発圏外
                cul_blast -= tmp.second;
                blast.pop();   // 先頭位置をずらす
            }else{
                break;
            }
        }
        M[i].H -= cul_blast;
        if(M[i].H <= 0){
            alive = false;
        }

        // 新しい爆発の追加
        if(alive){
            ll pos = M[i].X + 2 * D;
            ll times = M[i].H;
            ans += times;
            cul_blast += times;
            blast.push(make_pair(pos, times));
        }
    }

    cout << ans << endl;

    return 0;
}

//=====================================================
// 関数群
//=====================================================

template<class X> void printArray(X array[], ll n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

template<class X> void printVector(vector<X> &v){
    rep(i, (int)v.size()){
        if(i)   cout << " ";
        cout << v[i];
    }
    cout << endl;
}

//二次元配列の表示
template<class X> void printDimention(vector< vector<X> > &dv){
    rep(i, (ll)dv.size()){
        rep(j, (ll)dv[i].size()){
            if(j)   cout << " ";
            cout << dv[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//mapの表示
template <class X> void printMap(X mp) {
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}

// 内部にpairを内包したvectorの表示
template <class X> void printVecPair(vector<X> &v){
    rep(i, (int)v.size()){
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

// 内部にVec_Pairを内包したvectorの表示
void printDV_Pair(vector<vector<pair<ll, ll> > > &v){
    rep(i, (int)v.size()){
        cout << i << endl;
        rep(j, (int)v[i].size()){
            cout << v[i][j].first << " " << v[i][j].second << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void printSet(set<ll> &S){
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        if(it != --S.end() ) cout << *it << " ";
        else    cout << *it << endl;
    }
}

ll RepeatSquaring(ll a, ll index){
    if(index == 0)  return  1;
    else if(index % 2 == 0){
        ll tmp = RepeatSquaring(a, index / 2);
        return tmp * tmp;
    }else{
        return a * RepeatSquaring(a, index - 1);
    }
}

/**
 * MODを使用した繰返し自乗法
 * a: 基数, index: 指数, M: MOD
 */
ll RepeatSquaring_MOD(ll a, ll index, ll M){
    // Nは基数、Pは指数、MはMOD
    if(index == 0)  return 1;
    if(index % 2 == 0){
        ll tmp = RepeatSquaring_MOD(a, index/2, M);
        return tmp * tmp % M;
    }else{
        return a * RepeatSquaring_MOD(a, index - 1, M) % M;
    }
}

//最大公約数(Greatest Common Divisor)
// ユークリッドの互除法使用。 0・負の数に対応
ll GCD (ll a, ll b){
    if(b == 0)  return abs(a);
    return  GCD(b, a % b);
}

//最小公倍数(Least Common Multiple)
ll LCM(ll m, ll n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;

    //lcm = m * n / gcd(m, n)
    return ((m / GCD(m, n)) * n);
}

// 割り算した時に余りが有る時だけ、+1の商を返す。
ll div_one(ll res, ll div){
    // res 割られる数、div 割る数
    return (res + div - 1)/div;
}