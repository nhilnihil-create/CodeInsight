#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int K;
  cin >> K;

  vector <int> a(K + 1);
  a[1] = 7 % K;
  for (int i = 2; i <= K; i++){
    a[i] = (a[i - 1] * 10 + 7) % K;
  }
  for (int i = 1; i <= K; i++){
    if (a[i] == 0){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
