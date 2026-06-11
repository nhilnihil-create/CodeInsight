#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int A, B, C, K; cin >> A >> B >> C >> K;
  int cnt = 0;
  for(int i = 0; i < (1 << K); i++) {
    bitset<7> bits(i);
    int a = A, b = B, c = C;
    for(int j = 0; j < K; j++) {
      if(bits.test(j)) b *= 2;
      else c *= 2;
    }
    if(a < b && b < c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}