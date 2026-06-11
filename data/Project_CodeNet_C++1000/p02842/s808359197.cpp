#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N;
  for(int i = 0; i < 47000; i++) {
    M = i * 1.08;
    if(M == N) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}