#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int M, D; cin >> M >> D;
  int result = 0;
  for (int i=1; i<=D; i++) {
    if (i%10>=2 && i/10>=2) {
      if ((i%10)*(i/10)<=M) result++;
    }
  }
  cout << result << endl;
  return 0;
}