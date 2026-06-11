#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()

int main() {
  //std::cout << std::fixed << std::setprecision(20);
  int64_t mod = 1e+9 + 7;
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  REP(i,N) cin >> A[i];

  int64_t sum = 0;
  
  FOR(i,0,60){
    int64_t p = 0;
    int64_t q = 0;
    REP(j,N){
      if((A[j] >> i) & 1) p++;
      else q++;    
    }
    //p %= mod;
    // %= mod;
    int64_t tmp = (1ll << i ) % mod;
    int64_t pq = p * q % mod;
    tmp = tmp * pq % mod;
    sum = (sum + tmp) % mod;
  }
  cout << sum << endl;
}