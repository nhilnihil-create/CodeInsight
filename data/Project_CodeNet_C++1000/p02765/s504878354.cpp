#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, R;
  cin >> N >> R;
  N = max(0, 10 - N);
  cout << R + 100 * N << endl;
}