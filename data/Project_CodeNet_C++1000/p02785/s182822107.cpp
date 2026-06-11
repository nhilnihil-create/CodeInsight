#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K; cin >> N >> K;
  vector<long> H(N);
  for (int i =0; i<N; i++) cin >> H.at(i);

  sort(H.begin(),H.end());
  reverse(H.begin(),H.end());
  
  long ans =0;
  for (int i=K; i<N; i++) {
    ans += H.at(i);
  }
  cout << ans << endl;
}