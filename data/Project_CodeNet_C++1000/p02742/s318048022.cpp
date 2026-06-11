#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  Int A, B; cin >> A >> B;
  if (A == 1 || B == 1) cout << 1 << endl;
  else if (A % 2 == 1 && B % 2 == 1) cout << A * B / 2 + 1 << endl;
  else cout << A * B / 2 << endl;
}
