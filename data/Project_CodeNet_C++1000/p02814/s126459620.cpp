#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b) {
  if (a > b) {
    swap(a,b);
  }
  if (b%a == 0) return a;
  return gcd(a,b%a);
}

long long lcm(long long a,long long b) {
  long long x;
  x = a / gcd(a,b);
  x *= b;
  return x;
}

int main() {
  long long N,M;
  cin >> N >> M;
  vector<long long> a(N);
  
  for (int i=0; i<N; i++) {
    cin >> a[i];
    a[i] /= 2;
  }
  
  long long BLCM = a[0];
  for (int i=1; i<N; i++) {
    BLCM = lcm(BLCM,a[i]);
    if (BLCM > M) {
      cout << 0 << endl;
      return 0;
    }
  }
  
  long long val;
  for (int i=0; i<N; i++) {
    val = BLCM / a[i];
    if (val % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  
  long long ans = M / BLCM;
  ans = (ans + 1) / 2;
    
  
  cout << ans << endl;
} 