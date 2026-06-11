#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K;
  cin >> N >> K;
  
  vector<int> H(N);
  for(int i = 0; i < N; i++) {
    cin >> H.at(i); 
  }
  
  sort(H.begin(), H.end());
  reverse(H.begin(), H.end());
  
  long long ans = 0;
  
  if(K >= N) cout << 0 << endl;
  
  else {
    for(int i = K; i < N; i++) {
      ans += H.at(i); 
    }
    cout << ans << endl;   
  }
  
}