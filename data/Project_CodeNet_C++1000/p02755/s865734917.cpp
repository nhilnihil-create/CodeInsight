#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B;
  cin >> A >> B;
  for (int i = 1; i < 2000; i++){
    int x = int(i * 0.08);
    int y = int(i * 0.1);
    if (x == A && y == B){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
