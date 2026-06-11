#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  int K; cin >> K;
  
  if (K == 32) cout << 51 << endl;
  else if (K == 24) cout << 15 << endl;
  else if (K == 16) cout << 14 << endl;
  else if (K == 8 || K == 12 || K == 18 || K == 20 || K == 27) cout << 5 << endl;
  else if (K == 28 || K == 30) cout << 4 << endl;
  else if (K == 4 || K == 6 || K == 9 || K == 10 || K == 14 || K == 21 || K == 22 || K == 25 || K == 26) cout << 2 << endl;
  else cout << 1 << endl;
}
