// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

template<typename T>
T powint (const T& x, const T& y) {
  T ret = 1;
  for(int i=0; i<y; ++i) ret *= x;
  return ret;
}

long long factorial(long long X) {
  long long ans = 1;
  for(int i=1; i<X+1 ; ++i) ans *= i;
  return ans;
}

std::map<long long, long long> prime_factor(long long n) {
  std::map<long long, long long> ret;
  for(long long i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1; // if n is prime number.
  return ret;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
  ll X, Y;
  cin >> X >> Y;

  if (2*X < Y || 2*Y < X) {
    cout << 0 << endl;
    return 0;
  }
  if ((X+Y)%3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll large, small;
  if (X > Y) {
    large = X;
    small = Y;
  }
  else {
    large = Y;
    small = X;
  }
  ll dist = (large + small)/3;
  ll numedge = small - (large + small)/3;
  ll ans = 1;
  ll tmp = dist;
  for (int i=0; i < numedge; ++i) {
    ans *= dist - i;
    ans %= MODA;
  }
  for (int i=2; i < numedge+1; ++i) {
    ans = ans * modinv(i, MODA) % MODA;
  }
  cout << ans << endl;
  return 0;
}