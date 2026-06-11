
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
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
#include <regex>
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
// if ( std::regex_match(S, std::regex("(dream|dreamer|erase|eraser)*")) ) std::cout << "YES" << std::endl;

#define rep(i,n)  for(int i = 0; i < (int)(n);    i++)
#define sz(x)     ((int)(x).size())
#define all(x)    (x).begin(),(x).end()

using ll = long long;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int n, s; std::cin >> n >> s;
  std::vector<int> A(n); rep(i,n) std::cin >> A[i];

  constexpr int smax = 3010;
  
  const ll mod = 998244353;
  std::vector<ll> c(smax, 0);
  c[0] = 1;
  rep(i,n) {
    auto d = c;
    rep(j,smax) {
      c[j] *= 2;
      c[j] %= mod;
    }
    rep(j,smax) {
      //std::cout << j << " to " << j+A[i] << " : " << c[j+A[i]] << " + " << d[j] << std::endl;
      if ( j+A[i] > 3010 ) continue;
      c[j+A[i]] += d[j];
      c[j+A[i]] %= mod;
    }
    //std::cout << i << " : ";
    //rep(j,smax) std::cout << c[j] << " ";
    //std::cout << std::endl;
  }
  std::cout << c[s] << std::endl;
  return 0;
}

