#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<string>K(N);
  vector<int>K_(N);
  for (int i = 0; i < N; i ++) cin >> K[i] >> K_[i];
  string X;
  cin >> X;
  int ans = 0;
  int i = N - 1;
  while(X != K[i]) {
    ans += K_[i];
    i --;
  }
  cout << ans << endl;
}