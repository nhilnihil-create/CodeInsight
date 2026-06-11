#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  long long D, cnt=0; 
  cin >> N >> D;
  vector<long long> X(N), Y(N);

  rep(i, N) {
    cin >> X[i] >> Y[i];
    if(sqrt((X[i]*X[i])+(Y[i]*Y[i])) <= D) cnt++;
  }
  cout << cnt << '\n';
}