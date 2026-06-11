#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;


int main(){
  ll X;
  cin >> X;

  auto jou = [](ll x){
    return x*x*x*x*x;
  };

  int left = -2000, right = 2000;
  FOR(i, left, right){
    FOR(j, left, right){
      if((jou(i) - jou(j)) == X){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}