#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()

// 最大公約数を返す
int64_t gcd(int64_t a, int64_t b) {
 if (b == 0) {
   return a;
 }
 return gcd(b, a % b);
}

// 最小公倍数を返す
int64_t lcm(int64_t a, int64_t b) {
 return a / gcd(a, b) * b;
}

int t(int64_t a){
  int i = 0;
  if( a == 0) return i;
  if( a % 2 != 0) return i;
  a /= 2;
  i++;
  return i + t(a);
}

int main() {

  int64_t N, M;
  
  cin >> N >> M;

  vector<int64_t> a(N,0);

  REP(i,N) cin >> a[i];
  REP(i,N) a[i] /= 2;

  int num = 0;
  num = t(a[0]);
  FOR(i,1,N){
    if(num != t(a[i])){
      cout << 0 << endl;
      return 0;
    }
  }
  REP(i,N) a[i] >>= num;
  M >>= num;
  int64_t lcm_ = 1;
  REP(i, N){
    lcm_ = lcm(lcm_,a[i]);
    if(lcm_ > M){
      cout << 0 << endl;
      return 0;
    }
  }

  int answer = (M/lcm_ +1)/2;

  cout << answer << endl;

  return 0;




  



}