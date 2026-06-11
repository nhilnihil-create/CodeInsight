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
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef tuple<int, int> tii;
typedef tuple<ll, ll> tll;

template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if(a > b) { a = b; return true; } return false; }
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

const ll infty = 1223372036854775807;
const double eps = 1e-8;

int main() {
    int n;
    cin >> n;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    map<int, int> cnt;
    rep(i, n) cnt[arr[i]] = 0;
    rep(i, n) cnt[arr[i]] += 1;
    vi freqs;
    for (const auto &item : cnt) {
        freqs.push_back(item.second);
    }
    int m = freqs.size();
    sort(all(freqs));
    //dbg(freqs);
    vi s(m+1); // s[n] := \sum i=0 to n-1 freqs[i]
    rep1(i, m) s[i] = s[i-1] + freqs[i-1];
    for (int k = 1; k <= n; ++k) {
        //dbg('k', k);
        int lo = 0, hi = n / k + 1;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            // sum i=0 to m-1 min(k, mid) / k >= mid then possible = true
            int idx = lower_bound(freqs.begin(), freqs.end(), mid) - freqs.begin();
            // [idx, m) = mid
            // [0, idx) : freqs[k]
            bool possible = (s[idx] + mid * (m - idx)) >= mid * k;
            //dbg("ans", mid, "possible", possible, "val", s[idx] + mid * (m - idx));
            if (possible) lo = mid;
            else hi = mid;
        }
        cout << lo << endl;
    }
}