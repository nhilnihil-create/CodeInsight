#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007 

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A[i]; 

  unordered_map<int, int> m;
  m[0] = 3;
  int ans=1;
  for(int i=0; i<N; i++) {
     ans = (ans * m[A[i]]) % MOD;
     m[A[i]+1]++;
     m[A[i]]--;
     if(m[A[i]]==0) m.erase(A[i]);
  }
  cout << ans << endl;
}
