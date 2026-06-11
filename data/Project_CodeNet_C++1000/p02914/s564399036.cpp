#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  vector<ull> a(N);

  ull Z = 0;
  rep(i,N){
    cin >> a[i];
    Z ^= a[i];
  }
  rep(i,N){
    a[i] &= ~Z;
  }

  //printf("Z = 0x%x\n", Z);

  // ここで、青色のxorをX、赤色のxorをY、その他をZとする。
  // Zはどのような分割をしても、かならず答えに現れるもの。
  // X+Y+Z = a[0] ^ a[1] ^ ... ^ a[n-1]
  // X ^ Y = 0 --> X = Y
  // なのでa[i]から幾つか選んで、そのxorの合計Xを最大化したい。
  // これを吐き出し法でやっていく。

  ll pivot = 0;
  for (ull bit=(((ull)1) << 63); bit > 0; bit = bit>>1) {
    //printf("bit=0x%lx\n", bit);
    ll t = -1;

    // pivot行を探す
    for (ll i=pivot; i<N; i++) {
      if ((a[i] & bit) != 0) {
        t = i;
        break;
      }
    }

    if (t == -1)
      continue; // そのbitはスキップ

    swap(a[pivot], a[t]);
    rep(i,N) {
      if (i == pivot)
        continue;
      if ((a[i] & bit) != 0) {
        a[i] ^= a[pivot];
      }
    }

    pivot++;
  }

  //rep(i,N){
  //  printf("a[%d]=0x%lx\n", i, a[i]);
  //}

  ull X = 0;
  rep(i,N) {
    X ^= a[i];
  }
  cout << 2*X + Z << endl;
  return 0;
}
