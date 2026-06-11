
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
 
#define  rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i>=0; i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }


int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int>  P(N);   rep(i, N) std::cin >> P[i];
  std::vector<int> UP(N+1); rep(i, N) UP[P[i]] = i;

  std::set<int> idx;
  ll ans = 0;
  for(int X=N; X>=1; X--) {
    int index = UP[X];

    int LL = -1, L = -1, R = N, RR = N;
    auto itr = idx.lower_bound(index);
    if (itr != idx.end()) {
      R  = *itr;
      itr++;
    }
    if (itr != idx.end()) RR = *itr;

    itr = idx.lower_bound(index);
    if (itr != idx.begin()) {
      itr--;
      L  = *itr;
    }
    if (itr != idx.begin()) {
      itr--;
      LL = *itr;
    }

    ll l1 = index - L, l2 = L - LL;
    ll r1 = R - index, r2 = RR - R;
    ans += (l1 * r2 + l2 * r1) * X;

    idx.insert(index);
  }
  std::cout << ans << std::endl;
  return 0;
}

