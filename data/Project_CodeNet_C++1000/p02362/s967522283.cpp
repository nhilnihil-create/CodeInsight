#define _GLIBCXX_DEBUG

#include"bits/stdc++.h"
using namespace std;

//loops
#define REP(i,n) for(int i=0;i<(ll)(n);i++)
#define REPD(i,n) for(int i=(ll)(n)-1;i>=0;i--)
#define OneToN(i,n) for(int i=1;i<(ll)(n+1);i++)
#define ZeroToN(i,n) for(int i=0;i<(ll)(n+1);i++)
#define AToB(i,a,b) for(int i=a;i<(ll)(b+1);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

//bitsearch
#define BITSEARCH(bit, n) for (int bit = 0; bit < (1<<n); ++bit)
#define isOne(bit, i) bit & (1<<i)


//arrays
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define add push_back

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<T> vec(first, last);
    return vec;
}

#define remove_unique(v) v.erase(unique(ALL(v)), v.end())

//comparision
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

//pair
#define fir first
#define sec second
#define mp make_pair

//types
#define ll long long
#define vec vector
#define cord2d pair<int,int>
//UNCOMMENT WHEN NEEDED
//#define int ll

//input
template <class T> T get(){ T s; cin >> s; return(s);}
#define gi get<int>()
#define gs get<string>()

template <class T> vector<T> getv(int n) { vec<T> v(n); REP(i, n) cin >> v[i]; return v; }
#define gim(n) getv<int>(n)
#define gsm(n) getv<string>(n)

//output
void print(int a){ cout << a << endl; }
void print(long long a){ cout << a << endl; }
void print(string a){ cout << a << endl; }
void print(char a){ cout << a << endl; }
void print(double a){ cout << a << endl; }
void print(double a, int dig){ cout << std::setprecision(dig) << a << endl; }

template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

template <class T = int>
void print(vec<T> v){ cout << v << endl; }

template <class T = int>
void print2dVec(vec<vec<T>> v2d){for(vec<T> v: v2d) {print(v);}}

void YesNo1(bool i = true){ return print(i?"Yes":"No"); }
void YESNO2(bool i = true){ return print(i?"YES":"NO"); }

//debug output
#define var_name(var) #var
template <class T> void debug(T &var, int nest = 0, string before = "") { cout << string("          ", nest) << before; print(var); }

//name replacement
#define y0 y0__
#define y1 y1__
#define j0 j0__
#define j1 j1__

//bool lambdas
#define lamb(exp) [](auto i){return exp;}
#define isEven [](int i){return i % 2 == 0;}
#define isOdd [](int i){return i % 2 != 0;}

//constants
const ll INF = 1e18;
const int MOD = 10000007;

//maths
int factorial(int k){ int sum = 1; for (int i = 1; i <= k; ++i) { sum *= i; } return sum; }

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
////////////////////

void Main() {
    //code here
    int v = gi, e = gi, r = gi;
    vec<int> d(v, 1000000);
    d[r] = 0;
    vec<vec<int>> edges;
    REP(i, e) {
        edges.add({gi, gi, gi});
    }
    vec<int> lastD;
    REP(i, v) {
        lastD = d;
        for(vec<int> edge: edges) {
            if (d[edge[0]] != 1000000) chmin(d[edge[1]], d[edge[0]] + edge[2]);
        }
        if (lastD == d) {
            break;
        } else if (i == v-1) {
            print("NEGATIVE CYCLE");
            return;
        }
    }
    for(auto a: d) {
        if (a == 1000000) print("INF");
        else {
            print(a);
        }
    }
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Main();
}

