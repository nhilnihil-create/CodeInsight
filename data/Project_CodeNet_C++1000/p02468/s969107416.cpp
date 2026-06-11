#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

/*
べき乗の計算
*/

using ull = unsigned long long;

/*
  aのn乗を m を法として計算したものを返す
  O[logn]
  [x^nは(x^2)^(n/2)に等しい]ことを利用して，
  再帰関数を用いて実装する．
*/

ull power(ull x, ull n, ull M){
  ull res = 1;
  if( n > 0 ){
    res = power(x, n / 2, M);
    if( n % 2 == 0) res = (res*res) % M;
    else res =(((res * res) % M) * x ) % M;
  }
  return res;
}



int main(){
  int m, n;
  cin >> m >> n;

  int mod = 1e9 + 7;
  ull ans = power(m, n, mod);

  cout << ans << endl;

  return 0;
}

