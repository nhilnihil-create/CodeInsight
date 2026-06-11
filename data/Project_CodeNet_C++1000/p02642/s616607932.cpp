#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
using ll = long long;
#define int ll
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
#define IOS\
    ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SORT(name) sort(name.begin(), name.end())
#define RSORT(name)\
    SORT(name);\
    reverse(all(name));
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
template <class T> inline void print(T x){ cout << x << '\n';}
template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#pragma endregion

vector<int> GetDivisor(int n) {
    vector<int> v;
    for(int i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            v.push_back(i);
            if(i != n / i) { v.push_back(n / i); }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

const int MAX_N = 100010;
int N;
V<> A;

signed main() {
    IOS;

    cin >> N;
    A.resize(N);
    map<int, int> isExist;
    REP(i, N) {
        cin >> A[i];
        isExist[A[i]]++;
    }
    int ans = 0;
    REP(i, N) {
        auto res = GetDivisor(A[i]);
        bool isFind = false;
        for(auto num : res) {
            if(num == A[i] && isExist[num] == 1) { continue; }
            if(isExist.count(num) > 0) { isFind = true; break; }
        }
        if(!isFind) { ans++; }
    }
    print(ans);

    return 0;
}
