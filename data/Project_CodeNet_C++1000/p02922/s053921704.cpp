#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N, M;
  cin >> N >> M ;
  int sum = N; 
  if (M == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i < M; i++) {
    if (sum >= M) {
      cout << i;
      return 0;
    }
    sum += N - 1;
  }
}