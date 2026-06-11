#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;


int main(){
  ll A, B, N;
  cin >> A >>  B >> N;
  if(N < B){
    cout << (A*(N))/ B << endl;
  }
  else{
    cout << (A*(B-1))/ B << endl;
  }
  return 0;
}