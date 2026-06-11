#include <iostream>
#include <vector>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  rep(i, N) cin >> h[i];

  int cnt = 0;
  rep(i, N) if (h[i] >= K) cnt ++;

  cout << cnt << endl;

  return 0;
}