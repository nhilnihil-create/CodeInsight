#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
typedef long long ll;
const ll MAXN = 1e5 + 2;
const ll MAXK = 5e2 + 2;
const ll MOD = 1e9 + 7;
const ll MODH = 1e9 + 9;
const int MAXLG = 20;
const long double PI = acos(-1);
const ll p = 41;
const long double EPS = 1e-4;
#define x first
#define y second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
ll binpow(ll a, ll b, ll m) {a %= m;ll res = 1;while (b > 0) {if (b & 1){res = res * a % m;}a = a * a % m;b >>= 1;
}return res;}



int main() {
  
 
 ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
  int n,x,t;
 cin >> n >> x >> t;
  int ans = 0;
  int tans = 0;
  while(ans < n)
  {
  	tans+=t;
  	ans+=x;
  }

  cout << tans << '\n';
  

  }