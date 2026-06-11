#define SORT(v) sort(v.begin(), v.end())
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <numeric>

// #include "ane.cpp"

#define INF (int)1e9
#define INFLL (long long)1e18
#define NMAX (1<<17) // 131072
#define MMAX 100005
#define MOD 100000
using namespace std;

// ??????????????¢??????????????¨db_printf()??????????????????
// #define DEBUG

//
//  ???????????????????§?
//

// ????????????????????¨????????¢???
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, p> lp;
typedef pair<ll, ll> llp;


// ???????????°??¨printf
void db_printf(const char* format, ...){
    #ifndef DEBUG
    return;
    #endif
    va_list arg;
    va_start(arg, format);
    vprintf(format, arg);  // ????????????????????????
    va_end(arg);
}

// n?¬??????????????????????????¬¬????????°???????????????????????¨???????????????????????????
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// Union-Find Tree
class UnionFindTree{
    struct node{
        int par;
    };
    std::vector<node> T;

    public:
    void init(int num){
        T.resize(num+1);    // ignore T[0]
        for (int i = 1; i <= num; ++i)
        {
            T[i].par = i;
        }
    }
    void unite(int x, int y){
        T[find(y)].par = find(x);
    }
    int find(int x){
        if (T[x].par == x) return x;
        else return T[x].par = find(T[x].par);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

// Segment Tree for Range Minimum Query
    // **********************************************************
    // *** important: all functions' variable,                ***
    // *** such as "index", "l", "r", etc., must be 0-origin. ***
    // **********************************************************
    // ********************************************
    // *** important: N_MAX must be power of 2. ***
    // ********************************************
template<typename T>
class SegmentTree{
    private:
    ll N;
    T INF_VAL;
    T dat[NMAX * 2]; // 0 origin, A[i] = dat[i + N]

    T _query(ll l, ll r, ll l_responsible, ll r_responsible, ll i_dat){
        db_printf("query(%lld, %lld, %lld, %lld, %lld) called\n",
            l, r, l_responsible, r_responsible, i_dat);
        if (r < l_responsible || r_responsible < l) return INF_VAL;
        else if(l <= l_responsible && r_responsible <= r) return dat[i_dat];
        else return min(_query(l ,r, l_responsible, (l_responsible + r_responsible) / 2, i_dat * 2),
                        _query(l, r, (l_responsible + r_responsible) / 2 + 1, r_responsible, i_dat * 2 + 1));
    }

    public:
    void init(ll _N, T _inf_val){
        N = 1; while(N < _N) N *= 2;
        INF_VAL = _inf_val;
        Fill(dat, _inf_val);
    }
    void set(int index, T val){
        int i_dat = index + N;
        dat[i_dat] = val;
        for (i_dat /= 2; i_dat > 0; i_dat /= 2)
        {
            dat[i_dat] = min(dat[i_dat * 2], dat[i_dat * 2 + 1]);
        }
    }
    T query(ll l, ll r){
        return _query(l, r, 0, N - 1, 1);
    }
    void dump(){
        cout << "*** SegTree dump begin ***\n";
        cout << "N = " << N << ", INF_VAL = " << INF_VAL << endl;
        for (int i = 1; i < N * 2; i *= 2)
        {
            for (int j = i; j < i * 2; ++j)
            {
                if(dat[j] == INF_VAL) cout << "INF ";
                else cout << dat[j] << " ";
            }
            cout << endl;
        }
        cout << "*** SegTree dump end ***\n";
    }
};

// Binary Indexed Tree for Range Sum Query
    // *******************************************
    // *** important: all functions' variable, ***
    // *** such as "i", must be 1-origin.      ***
    // *******************************************
template<typename T>
class BinaryIndexedTree{
    private:
    ll N;
    T dat[NMAX + 1]; // 1 origin, A[i] = sum(i) - sum(i-1)

    public:
    void init(ll _N){
        N = _N;
        Fill(dat, 0);
    }
    void add(int i, T val){
        while(i <= N) {
            dat[i] += val;
            i += i & -i;
        }
    }
    T sum(ll i){
        T ret = 0;
        while(i > 0) {
            ret += dat[i];
            i -= i & -i; // set last HIGH bit to LOW
        }
        return ret;
    }
    T sum(ll left, ll right){
        return sum(right) - sum(left - 1);
    }
    void dump(){
        cout << "*** BITree dump begin ***\n";
        cout << "N = " << N << endl;
        for (int i = 1; i <= N; i *= 2)
        {
            cout << dat[i] << " ";
        }
        cout << "*** BITree dump end ***\n";
    }
};

//
// ?????????????????????
//


ll N,M,K,A,B,C,D,E;
// int dp[NMAX][MMAX] = {};
BinaryIndexedTree<int> bitree;

static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

ll ans = 0;

void solve(){
    // ?§£?????¢?????´?????????
}
void debug(){
    // ???????????°??¨??????
    bitree.dump();
}
void answer(){
    // ?§£?????????
    // printf("%lld\n", ans);
}
int main(int argc, char const *argv[])
{
    // ??\??????????????????????????????

    scanf("%lld%lld", &N,&M);
    bitree.init(N);
    for (int i = 0; i < M; ++i)
    {
        int c, x, y;
        scanf("%d%d%d", &c,&x,&y);
        if (c)
        {
            printf("%d\n", bitree.sum(x, y));
        }else
        {
            bitree.add(x, y);
        }
    }
    solve();
    #ifdef DEBUG
    debug();
    #endif
    answer();

    return 0;
}