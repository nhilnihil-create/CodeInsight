#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K, Q, A;
  cin >> N >> K >> Q;
  vector<int> player(N, 0);
  for(int i = 0; i < Q; i++) {
    cin >> A;
    player[A - 1]++;
  }

  for(int i = 0; i < N; i++) {
    if(K - (Q - player[i]) <= 0) {
      cout << "No" << endl;
    }
    else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
