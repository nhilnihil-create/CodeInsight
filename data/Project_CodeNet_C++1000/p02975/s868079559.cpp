#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long a, b;
  cin >> a;
  for(int i = 0; i < N - 1; i++){
    cin >> b;
    a ^= b;
  }
  cout << (a == 0?"Yes":"No") << endl;
  return 0;
}
