#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int N; cin >> N;
  for (int i=1; i<=N; i++) {
    for (int j=i+1; j<=N; j++) {
      int ti = i, tj = j, count = 0;
      while ((ti&(1<<count))==(tj&(1<<count))) count++;
      cout << count+1 << " ";
    }
    cout << endl;
  }
  return 0;
}