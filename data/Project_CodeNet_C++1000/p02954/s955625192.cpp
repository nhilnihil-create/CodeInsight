#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define rrepSE(i,s,e) for (int i = (s); i > (e); i--)
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
#define DEBUG_PRINT(var) std::cout << #var << " = " << var << "\n";

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> sb(n), ans(n);
    rep(i,n) { sb[i] = (s[i] == 'R') ? 0 : 1;}
    vector<pint> res(1, pint(sb[0], 0));
    for (int p : sb) {
        if (res.back().first == p) {
            res.back().second ++;
        }
        else {
            res.emplace_back(p, 1);
        }
    }
    int accum = 0;
    for (int i = 0; i < res.size(); i+=2) {
        int sR = res[i].second;
        int sL = res[i+1].second;
        if (sR%2 == 0 && sL%2 == 0) {
            ans[accum + sR - 1] = sR/2 + sL/2;
            ans[accum + sR] = sR/2 + sL/2;
        } else if (sR%2 == 1 && sL%2 == 0) {
            ans[accum + sR - 1] = (sR+1)/2 + sL/2;
            ans[accum + sR] = sR/2 + sL/2;
        } else if (sR%2 == 0 && sL%2 == 1) {
            ans[accum + sR - 1] = sR/2 + sL/2;
            ans[accum + sR] = sR/2 + (sL+1)/2;
        } else if (sR%2 == 1 && sL%2 == 1) {
            ans[accum + sR - 1] = (sR+1)/2 + sL/2;
            ans[accum + sR] = sR/2 + (sL+1)/2;
        }
        accum += sR + sL;
    }
    rep (i,n) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
