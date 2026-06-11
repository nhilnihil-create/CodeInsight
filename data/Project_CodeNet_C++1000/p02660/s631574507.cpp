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
// 繰返し自乗法 MOD
ll RepeatSquaring_MOD(ll a, ll index, ll M);
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

//===================================================
// 関数
//===================================================

/**
 * 素因数分解系 abc152-e参考
 * 以下の配列は素数判定（エラトステネス → 素因数分解）で使用する
 * isprime, min_factor の上限値は素因数分解対象の平方根
 */
// Eratosthenes
Vector primes;          // 素数を格納
vector<bool> isprime;   // 素数かどうかを判定。isprime の添え字と見たい数は数値を一致させる（要素数をn + 1で確保）
Vector min_factor;      // min_factor[num] : numを割り切る最小の素数を格納
bool called_Eratosthenes = false;   // 既にエラトステネスの篩をやった
bool can_min_factor;     // 素因数分解対象が lim <= 10^8 なので min_factor が使える

/**
 * 使用方法
 * prime_factorization() を呼ぶことで、内部でエラトステネスの篩が呼び出され、
 * 高速に素因数分解ができるようになります
 * 
 * ex) Ai を素因数分解したい。問題だと Ai の上限値は lim = 10^6
 *     prime_factorization(Ai, lim)
 * 素因数分解の結果を格納。first: 素因数、second: 指数
 */

/**
 * 素因数分解を高速にやるためにエラトステネスの篩を活用する
 * @brief isprime, min_factor を設定する
 * @param lim 素因数分解対象の上限値
 */
void Eratosthenes(ll lim){
    
    isprime.resize(lim + 1, true);    // 素数かどうかを判定。isprime の添え字と見たい数は数値を一致させる（要素数をlim + 1で確保）
    min_factor.resize(lim + 1, -1);   // min_factor[num] : numを割り切る最小の素数を格納
    
    isprime[0] = isprime[1] = false;
    min_factor[0] = 0, min_factor[1] = 1;
    // num を p = min_factor[num] で割れるだけ割る」というのを num = 1 となるまで繰り返す
    // num の添字分まで必要なので、回すループの上限は
    // min_factorが必要でない。 prime に素数の実態がなくてよい場合、
    // iの上限はsqrt(n)まで。素数かどうかの判定はisprimeで可能。
    for(int i = 2; i <= lim; i++){   // 素数
        if(!isprime[i]) continue;
        primes.push_back(i);
        min_factor[i] = i;
        for(int j = i * 2; j <= lim; j += i){   // 素数の倍数を省く
            isprime[j] = false;
            if(min_factor[j] == -1) min_factor[j] = i;  // まだ格納されていなければ
        }
    }
}
/**
 * この関数の呼び出し元で以下のように使用する
 * vector< vector<pair<ll, ll>> >    map;
 * map[i] = prime_factorization(n)
 *
 * @brief num を素因数分解した結果を res_pf に格納する
 * @param num 素因数分解対象
 * @param lim 素因数分解対象の上限値（複数回呼ばれることを見越して）
 * @return res_pf Vec_pair型で、first: 素因数, second: 指数
 */
Vec_Pair prime_factorization(ll num, ll lim){
    Vec_Pair res_pf;
    // どちらの素因数分解を使うかの判定
    if(lim <= pow(10, 8)) can_min_factor = true;
    else    can_min_factor = false;

    if(!called_Eratosthenes){   // 既にエラトステネスの篩を読んでいるかどうか
        if(can_min_factor){
            Eratosthenes(lim);
        }else{
            lim = sqrt(lim);    // min_factor が使えないので、sqrt(num) までを調べる方に切り替える
            Eratosthenes(lim);
        }
        called_Eratosthenes = true;
    }

    if(num < 2){    // 素因数分解できない
        // error処理
        // cout << "Error: can't do prime_factorization" << endl;
        // res_pf.push_back(make_pair(1, 1));
        return res_pf;
    }
    res_pf.clear();

    if(can_min_factor){ // 高速素因数分解
        // example
        // n = 120
        // min_factor[120] = 2 → 120 / 2 をし続ける → n = 15
        // min_factor[15] = 3 → 15 / 3 をし続ける → n = 5
        // min_factor[5] = 5 → 5 / 5 をし続ける → n = 1  終わり
        while(num != 1){
            int prime = min_factor[num];
            int cnt = 0;
            while(min_factor[num] == prime){
                num /= prime;
                cnt++;
            }
            res_pf.push_back(make_pair(prime, cnt));
        }
    }else{  // 愚直な素因数分解 エラトステネスの篩の結果(prime)を使うバージョン
        // lim が 10^8 以上で min_factor が使用できないので、squrt上限で愚直に素因数分解
        // 小さい素数の方から割っていく。primes: 素数を格納。
        bool num_is_prime = true; // 今のnumは素数
        ll index = 0;   // Vector primes の添字
        int cnt = 0;
        while(index < primes.size()){
            int prime = primes[index];
            if(num % prime == 0){
                num_is_prime = false;
                num /= prime;
                cnt++;
            }else{  // この素数ではもう割れない
                index++;
                res_pf.push_back(make_pair(prime, cnt));
                cnt = 0;
            }
            // 終了処理
            if(num == 1){   // 割っていって元の数が 1 になったら終了。最後の約数を追加
                res_pf.push_back(make_pair(prime, cnt));
                break;
            }else if(index == primes.size() - 1){    // numが1になる前に、素数のリストが尽きた -> 素数のリストに無い、範囲外の素数が出てきた
                num_is_prime = true;
            }
        }
        if(num_is_prime){ // num が 素数の場合の処理。squrt の範囲にかからないため
            // cout << "num is prime: num = 1 * num" << endl;
            res_pf.push_back(make_pair(num, 1));
        }
    }
    return res_pf;
}

//===================================================
// main 問題処理部
//===================================================
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    ll lim = pow(10, 12);
    Vec_Pair res = prime_factorization(N, lim);

    ll cnt = 0;
    for(auto p : res){
        ll i = 1;
        while(p.second >= i){
            p.second -= i;
            cnt++;
            i++;
        }
    }
    cout << cnt << endl;

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
        return (tmp * tmp) % M;
    }else{
        return (a * RepeatSquaring_MOD(a, index - 1, M)) % M;
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