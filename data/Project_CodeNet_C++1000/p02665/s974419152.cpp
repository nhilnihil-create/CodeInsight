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

int A[1<<20], N;
ll ans = 0;
ll maxm[1<<20];

ll answer_of(ll x, int j, ll y, int i) {
  int l = 0;
  // x*2^l < y : maxl
  while(x*(1LL << l) < y) l++;l--;

  return x*((1LL << (l+1)) - 1) + y*(i-j-l) - x;
}

int main() {

//  freopen("input.in","r",stdin);
//  freopen("output.out","w",stdout);
  cin>>N;N++;
  rep(i, N) cin >> A[i];

  if(N == 1) {
    if(A[0] == 1) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
    return 0;
  }

  if(A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  maxm[0] = 1;int i = 0;
  repi(j,1,N-1) {
    if(A[j] != 0) {
      if(j-i >= 45) maxm[j] = 1e13 - A[j];
      else if((1LL << (j-i)) <= (1e13)/maxm[i]) {
        maxm[j] = maxm[i]*(1LL << (j-i)) - A[j];
      } else {
        maxm[j] = 1e13 - A[j];
      }

      if(maxm[j] <= 0) {
        cout << -1 << endl;
        return 0;
      }

      i = j;
    }
  }

  int j = N-2; i = N-1;
  ll val = A[j+1], valf = A[j+1];
  while(j >= 0) {
    val = (val+1)/2;
    if(maxm[j] != 0) {
      if(maxm[j] < val) {
        cout << -1 << endl;
        return 0;
      }
      maxm[j] = min(maxm[j], valf);

      // maxm[j] (j), valf (i)
      ans += answer_of(maxm[j], j, valf, i);
      // debug(ans);

      val = valf = maxm[j] + A[j];
      i = j;
    }

    j-=1;
  }

  // rep(i,N) cout << A[i] << " ";cout<<endl;
  // rep(i,N) cout << maxm[i] << " ";cout<<endl;
  cout << ans+1;




  return 0;
}
