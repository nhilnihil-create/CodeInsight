#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000000;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){
  int X, Y;
  cin >> X >> Y;
  int ans = 0;
  if(X == 1) ans += 3 * 1e5;
  else if(X == 2) ans += 2 * 1e5;
  else if(X == 3) ans += 1e5; 

  if(Y == 1) ans += 3 * 1e5;
  else if(Y == 2) ans += 2 * 1e5;
  else if(Y == 3) ans += 1e5;

  if(X == 1 && Y == 1) ans += 4 * 1e5;
  print(ans);
}
