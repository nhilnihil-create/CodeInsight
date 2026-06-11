#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  int n,k,c;
  string s;
  cin >> n >> k >> c >> s;

  auto check = [&]() {
    vector<int> res(n, -1);
    int t = 0;
    int sz = 0;
    for (int i = 0; i < n && sz < k;) {
      if (s[i] != 'x') {
        res[i] = t;
        t += 1;
        i += c+1;
        sz += 1;
      } else {
        i ++;
      }
    }

    return res;
  };

  auto left = check();
  reverse(s.begin(), s.end());
  auto right = check();
  for (auto &itr : right) {
    if (itr != -1) itr = k - 1 - itr;
  }
  reverse(right.begin(), right.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (left[i] != -1 && right[i] != -1 && left[i] == right[i]) {
      cout << i+1 << endl;
    }
  }
}

// 3回目に働く日は10日目以降
