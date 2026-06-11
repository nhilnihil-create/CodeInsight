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
  ll N;
  cin >> N;
  
  auto dfs = [&](auto&& f, int keta, ll sum){
    sum *= 26;
    if(N <= sum){
      N--;
      string ans(keta, 'a');
      int id = keta-1;
      while(N){
        ans[id] = N % 26 + 'a';
        N /= 26;
        id--;
      }
      cout << ans << endl;
      return;
    }
    N -= sum;
    f(f, keta+1, sum);
  };
  
  dfs(dfs, 1, 1);
  return 0;
}