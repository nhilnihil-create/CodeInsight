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

int Combination(int n, int r) {
  if ( r * 2 > n ) r = n - r;
  int dividend = 1;
  int  divisor  = 1;
  for (int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}


ll Choice(ll a)
{
    return a * (a-1)/2;
}

int main()
{
    int n, t;
    ll ans, sum =0;
    cin >> n;
    vector <int> A(n);
    rep(i, n){
         cin >> t; 
         A[i] = t-1;
    }
    vector <int> d(n);
    rep(i, n) d[A[i]]++;
    rep(i, n) sum += Choice(d[i]);

    rep(i, n) {
        ans = sum;
        ans -= Choice(d[A[i]]);
        ans += Choice(d[A[i]] - 1);
        cout << ans << endl;
    }
    

}
