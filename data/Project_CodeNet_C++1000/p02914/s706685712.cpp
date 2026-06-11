#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iterator>
#include <valarray>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <tuple>
#include <initializer_list>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define all(c) (c).begin(),(c).end()
using ll = long long;
using tii = tuple<int, int>;
using tll = tuple<ll, ll>;
template<typename T = int> using V = vector<T>;
template<typename T = int> using VV = vector<vector<T>>;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
#ifdef DBG
template<typename T> ostream &operator<<(ostream &os, set<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, multiset<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp) { if (mp.size() == 0) return os << "{}"; os << "{" << endl; decltype(mp.begin()) iter; for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) { --iter; os << "  {" << iter->first << ", " << iter->second << "}," << endl; ++iter; } --iter; os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, unordered_set<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, unordered_multiset<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T, typename U> ostream &operator<<(ostream &os, unordered_map<T, U> const &mp) { if (mp.size() == 0) return os << "{}"; os << "{" << endl; decltype(mp.begin()) iter; for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) { --iter; os << "  {" << iter->first << ", " << iter->second << "}," << endl; ++iter; } --iter; os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, vector<T> const &v) { os << '['; rep(i, v.size()-1) os << v[i] << ", "; if (v.size() > 0) os << v[v.size()-1]; cerr << ']'; return os; }
template<typename T, unsigned N, unsigned Last> struct TuplePrinter { static void print(ostream &os, T const& v) { os << std::get<N>(v) << ", "; TuplePrinter<T, N + 1, Last>::print(os, v); } };
template<typename T, unsigned N> struct TuplePrinter<T, N, N> { static void print(ostream &os, T const &v) { os << std::get<N>(v); } };
template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v) { os << "("; TuplePrinter<tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, v); os << ")"; return os; }
template<typename T> void _dbg(T const &t) { cerr << t << endl; }
template<typename T, typename... Args> void _dbg(T const &t, Args... args) { cerr << t << " "; _dbg(args...); }
template<typename... Args> void __dbg(const char *fn, int l, Args... args) { cerr << "[" << fn << ":" << l << "] "; _dbg(args...); }
#define dbg(...) __dbg(__func__, __LINE__, __VA_ARGS__)
#else
#define dbg(...)
#endif
const ll infty = 1223372036854775807LL;
const double eps = 1e-8;

void solve() {
    int n;
    cin >> n;
    V<ll> a(n);
    rep(i, n) cin >> a[i];
    ll xored = 0;
    rep(i, n) xored ^= a[i];
    rep(i, n) a[i] &= ~xored;
    const int N = 60;
    int r = 0;
    #define AT(x,y) ((a[x] >> y) & 1) // AT(row, col)
    for (int i = N; r < n && i >=0; --i) { // i: col(bit) in msb to lsb order, r: row
        int pivot = r;
        for (int j = r; j < n; ++j) { // find pivot row
            if (AT(j, i) != 0) {
                pivot = j;
                break;
            }
        }
        swap(a[r], a[pivot]);
        if (AT(r, i) == 0) continue; // skip null column
        rep(j, n) if (j != r && AT(j, i) != 0) {
            a[j] ^= a[r];
        }
        ++r;
    }
    ll additional = 0;
    rep(i, r) additional ^= a[i];
    cout << xored + additional * 2 << endl;
}

int main() {
#ifdef DBG
    ifstream cin("in.txt");
    std::cin.rdbuf(cin.rdbuf());
    //ofstream cout("out.txt");
    //std::cout.rdbuf(cout.rdbuf());
#else
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
#endif
    solve();
    return 0;
}
