#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C, K;
  cin >> A >> B >> C >> K;

  bool judge = false;

  for(int i = 0; i <= K; i++) {
    for(int j = 0; j <= K; j++) {
      int B_d = B * (1 << i), C_d = C * (1 << j);
      if(i + j <= K && A < B_d && B_d < C_d) judge = true;
    }
  }
  if(judge) {
    cout << "Yes" << endl;
  }
  else {
  cout << "No" << endl;
  }

  return 0;
}
