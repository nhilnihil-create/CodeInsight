#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K, X;
  cin >> N >> K;
  X = K;
  
  long long ans = 0;
  
  for(int i = 0; i < N; i++) {    
    ans++;
    if(N < X) {
      cout << ans << endl;
      break;
    }
    else X = X * K;
  }
  
}