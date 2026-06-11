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
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  REP(i, N){
    cin >> A[i];
    mp[A[i]]++;
  }
  
  int ans = 0;
  REP(i, N){
    if(mp[A[i]] >= 2) continue;
    if(A[i] != 1 && mp[1]) continue;
    bool flag = true;
    for(int x = 2; x*x <= A[i]; x++){
      if(A[i] % x != 0) continue;
      if(mp[A[i]/ x]) flag = false;
      if(mp[x]) flag = false;
    }
    if(flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
