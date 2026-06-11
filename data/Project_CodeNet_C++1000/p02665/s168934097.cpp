#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#define MOD 1000000007LL

ll n;
vector<ll> a, v, as;

ll t2(int);

ll vn(int, ll);

int main()
{
  ll ans;
  int i, d;
//  int j;
//  ll dn;
//  ll tx;
/*
  for (i=0; i<=100; i++) {
    printf("2^%d = %lld\n", i, t2(i));
  }
*/

  cin >> n;
  a.resize(n+1);
  as.resize(n+1);
  v.resize(n+1);
  for (i=0; i<=n; i++) {
    cin >> a[i];
  }

  if (n==0) {
    if (a[0] == 1) {
      printf("1\n");
    } else {
      printf("-1\n");
    }
    return 0;
  } else {
    if (a[0] != 0) {
      printf("-1\n");
      return 0;
    }
  }

  as[n]=a[n];
  for (i=n-1; i>=0; i--) {
    as[i] = as[i+1] + a[i];
//printf("as[%d] = %lld a[%d] = %lld\n", i, as[i], i, a[i]);
  }

  as[0] = 1;
  for (d=1; d<n; d++) {
    as[d] = min((as[d-1] - a[d-1])*2, as[d]);
//printf("as[%d] = %lld a[%d] = %lld\n", d, as[d], d, a[d]);
    if (as[d] - a[d] < 1) {
      printf("-1\n");
      return 0;
    }
  }
  if ((as[n-1] - a[n-1])*2 < a[n]) {
    printf("-1\n");
    return 0;
  }

  ans=0;
  for (i=0; i<=n; i++) {
    ans += as[i];
  }

  cout << ans << endl;
  return 0;
}

ll t2(int i) {
  if (i > 62) {
    return 4611686018427387904LL;
  }
  switch(i) {
  case 0: return 1; 
  case 1: return 2; 
  case 2: return 4; 
  case 3: return 8; 
  case 4: return 16; 
  case 5: return 32; 
  case 6: return 64; 
  case 7: return 128; 
  case 8: return 256; 
  case 9: return 512; 
  case 10: return 1024; 
  case 11: return 2048; 
  case 12: return 4096; 
  case 13: return 8192; 
  case 14: return 16384; 
  case 15: return 32768; 
  case 16: return 65536; 
  case 17: return 131072; 
  case 18: return 262144; 
  case 19: return 524288; 
  case 20: return 1048576; 
  case 21: return 2097152LL; 
  case 22: return 4194304LL; 
  case 23: return 8388608LL; 
  case 24: return 16777216LL; 
  case 25: return 33554432LL; 
  case 26: return 67108864LL; 
  case 27: return 134217728LL; 
  case 28: return 268435456LL;
  case 29: return 536870912LL;
  case 30: return 1073741824LL;
  case 31: return 2147483648LL;
  case 32: return 4294967296LL;
  case 33: return 8589934592LL;
  case 34: return 17179869184LL;
  case 35: return 34359738368LL;
  case 36: return 68719476736LL;
  case 37: return 137438953472LL;
  case 38: return 274877906944LL;
  }
  return t2(i-38)*274877906944LL;
}
