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

// struct Sieve {
//     int n;
//     vector<int> f, primes;
//     Sieve(int n = 1):n(n), f(n+1) {
//         f[0] = f[1] = -1;
//         for(ll i = 2; i <= n; i++) {
//             if (f[i]) continue;
//             primes.push_back(i);
//             f[i] = i;
//             for (ll j = i*i; j <= n; j += i) {
//                 if (!f[j]) f[j] = i;
//             }
//         }
//     }
//     bool isPrime(int x) { return f[x] == x;}
//     vector<int> factorList(int x) {
//         vector<int> res;
//         while (x != 1) {
//             res.push_back(f[x]);
//             x /= f[x];
//         }
//         return res;
//     }
//     vector<pint> factor(int x) {
//         vector<int> fl = factorList(x);
//         if (fl.size() == 0) return {};
//         vector<pint> res(1, pint(fl[0], 0));
//         for (int p : fl) {
//             if (res.back().first == p) {
//                 res.back().second ++;
//             }
//             else {
//                 res.emplace_back(p, 1);
//             }
//         }
//         return res;
//     }
// };

// const int MX = 1e6;

bool isPrime(int n)
{
  bool flag = false;
  for(int i = 2; i*i <= n; ++i) {
      if(n%i == 0) {
          flag = true;
          break;
      }
  }
  return flag;
}

int main()
{
    int n;
    cin >> n;
    // Sieve si(MX);
    int i = n;
    while (isPrime(i)) i++;
    cout << i << "\n";
    return 0;
}
