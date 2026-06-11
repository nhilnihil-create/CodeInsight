#include <bits/stdc++.h>
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)


#define SZ(x) ((int)(x).size())


typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Vector{
    double x, y;
};

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

int facctorial(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

int Combination(int n, int r) {
  if ( r * 2 > n ) r = n - r;
  int dividend = 1;
  int  divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int main()
{
    int n,m, ans = 0;
    cin >> n >> m;
    if (n >= 2) ans += Combination(n, 2);
    if (m >= 2) ans += Combination(m, 2);
    cout << ans << endl;
    return 0;
}
