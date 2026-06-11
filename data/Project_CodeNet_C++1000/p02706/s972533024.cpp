#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  int ans = 0;
  for (int i = 0; i < M; i++) {
    int A;
    cin >> A;
    ans += A;
  }
  if (ans > N) {
    cout << "-1" << endl;
  }
  else {
    cout << N - ans << endl;
  }
}
    
