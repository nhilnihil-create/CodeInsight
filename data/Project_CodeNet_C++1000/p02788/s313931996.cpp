#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define ssort(v) sort(v.begin(), v.end())
#define gsort(v) sort(v.rbegin(), v.rend())
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n = 0):n(n),d(n+1) {}
    void add(int i, T x = 1) {
        for(i++; i <= n; i+= i&-i) {
            d[i] += x;
        }
    }
    T sum (int i) {
        T x = 0;
        for(i++; i; i -= i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main()
{
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pll> XH(N);
    rep(i,N) {
        cin >> XH[i].first >> XH[i].second;
    }
    ssort(XH);
    ll ans  = 0;
    // queue<pll> que;
    // ll accum = 0;
    // rep(i,N) {
    //     int x = XH[i].first;
    //     int h = XH[i].second;
    //     while (!que.empty() && que.front().first < x) {
    //         accum -= que.front().second;
    //         que.pop();
    //     }
    //     h -= accum;
    //     if (h > 0) {
    //         int num = (h-1)/A + 1;
    //         h -= num*A;
    //         accum += num*A;
    //         que.emplace(x+2*D,num*A);
    //         ans += num;
    //     }
    // }
    BIT<ll> d(N+1);
    rep(i,N) {
        ll x = XH[i].first;
        ll h = XH[i].second;
        h -= d.sum(i);
        if (h > 0) {
            ll num = (h-1)/A + 1;
            ll dmg = num*A;
            d.add(i, dmg);
            ll rx = min(x+2*D, 1001001001ll);
            int jd = upper_bound(XH.begin(), XH.end(), pll(rx+1, -1)) - XH.begin();
            d.add(jd, -dmg);
            h -= dmg;
            ans += num;
        }
    }
    cout << ans << "\n";
    return 0;
}
