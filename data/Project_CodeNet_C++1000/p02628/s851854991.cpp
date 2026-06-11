#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int   N, K;
  string S;
  cin >> N >> K;
  vector<long long int> P(N);
  for(long long int i = 0; i < N; i++) cin >> P[i];
  
  sort(P.begin(),P.end());
  long long int ans = 0;
  for(long long int i = 0; i < K; i++) ans += P[i];
  cout << ans << endl;
}
