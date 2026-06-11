#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> H(N);
  if(K>=N) {
    cout << 0 << endl;
    return 0;
  }
  else {
    for(int i =0; i<N; i++) {
      cin >> H.at(i);
    }
  }
  sort(H.begin(),H.end());
  long long ans = 0;
  for(int i=0; i<N-K; i++) ans += H.at(i);
  cout << ans << endl;
}