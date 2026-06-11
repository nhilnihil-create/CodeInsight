#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <class T>
T inf = numeric_limits<T>::max();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k,a,b;
  cin >> k >> a >> b;
  
  for (int i = a; i <= b; ++i) {
    if (i % k ==0) {
      cout << "OK" << endl;
      return 0;
    }
  }

  cout << "NG" << endl;
}
