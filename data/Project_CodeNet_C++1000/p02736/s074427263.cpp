#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const long double pi = 3.141592653589793;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repi(i, j, n) for(int i = j;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define F first
#define S second

// #define COMMENT

/*

const int NN = 200090;
ll fact[NN];
ll finv[NN];
ll inv[NN];

void inverse_modulao() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2;i < NN;i++) {
    fact[i] = fact[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll nCr(int n, int r) {
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}

*/

bool ncrmod2(int n,int r) {
  /* using lucas formula
   * http://www.cecm.sfu.ca/organics/papers/granville/paper/binomial/html/node2.html
  */
  while(n > 0) {
    if(!(n & 1) & (r & 1)) return 0;
    n >>= 1;
    r >>= 1;
  }
  return 1;
}

int N;string s;

int main() {

  //freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

  cin >> N >> s;
  bool ans = 0, one = 0;
  rep(i, N) {
    bool ib = (s[i]-'1') & 1;
    if(ib) {

      ans ^= ncrmod2(N-1, i);
      one = true;
    }
  }
  if(ans) {cout << 1 << endl;return 0;}
  if(one) {cout << 0 << endl;return 0;}

  rep(i, N) {
    bool ib = (s[i]-'1') >> 1;
    if(ib) {

      ans ^= ncrmod2(N-1, i);
    }
  }

  cout << (ans ? 2 : 0) << endl;


  return 0;
}
