#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans=0;
  cin >> N;
  
  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) {
      if(i*j == N) {
        ans = 1;
        break;
      }
    }
  }
  
  if(ans == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}

