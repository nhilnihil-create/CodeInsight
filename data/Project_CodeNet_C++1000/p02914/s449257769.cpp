#include <bits/stdc++.h>
// #include<iostream>
// #include<stack>
// #include<string>
// #include<vector>
// #include<queue>
// #include<map>
// #include<algorithm>
// #include<iomanip>
// #include<set>
// #include<bitset>
// #include<cmath>
// #include<numeric>
// #include<limits>
// #include<functional>
// #include <bitset>

#define REP(i, m, n) for(int i = (m); i < (n); i++)
#define rep(i,n) REP(i,0,n)
#define NIL -1
using namespace std;
typedef long long ll;
typedef long long int lli;
static const int MOD = 10000007;
static const int MAX = 100005;
// static const int NMAX = 5005;

// typedef priority_queue<int, greater<int>> RevQ;
int N, L;
// vector<ll> a(MAX);



int main(){
  cin >> N;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  ll s = 0;
  rep(i, N) s ^= a[i]; // bit-wise XOR (total XOR)
  ll ans = s;
  rep(i, N) a[i] &= ~s; // bit-wise AND
  // A[i]'s j-th digit takes value 1 only if A[i]'s j-th digit is 1 and
  // s's j-th digit is zero.

  // 掃き出し法
  int r = 0; // rank
  vector<int> top(N); // 先頭ビットが何 bit 目か
  for(int i = 60; i >= 0; --i){
    int j = r;
    for(; j < N; ++j) {
      if (a[j] >> i & 1) { // A[j]'s j-th digit is 1
        swap(a[r], a[j]);
        break;
      }
    }
    if (j == N) continue; // We cannot find 
    top[r] = i;
    rep(k, N) {
      if ( r == k ) continue;
      if ( a[k] >> i & 1) a[k] ^= a[r];
    }
    ++r;
  }

  ll x = 0;
  for ( int i = 60; i >= 0; --i) {
    ll nx = x | (1ll << i);
    {
      ll b = nx;
      rep(j, r) {
        if (b >> top[j] & 1) b ^= a[j];
      }
      if ((b&nx) == 0) {
        x = nx;
      }
    }
  }
  ans += x*2;
  cout << ans << endl;
  return 0;
}


/* standard input
19
strangexyxxorangexx

*/
