#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

long long gcd(long long a, long long b) {
  if(a % b == 0) {
    return b;
  }
  long long d;
  a = a % b;
  swap(a, b);
  d = gcd(a, b);
  return d;
}

long long N, M;
long long a[100000];

int main() {
  cin >> N >> M;
  rep(i, N) {
    cin >> a[i];
  }
  rep(i, N) {
    a[i] /= 2;
  }
  long long l = a[0];
  rep(i, N-1) {
    long long d = gcd(l, a[i+1]);
    l = l * a[i+1] / d;
  }
  
  rep(i, N) {
    if((l / a[i]) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long ans;
  ans = M / l;
  if(ans % 2 == 0) {
    ans = ans / 2;
    cout << ans << endl;
  } else {
    ans = (ans + 1) / 2;
    cout << ans << endl;
  }
  // cout << l << endl;
  return 0;
}