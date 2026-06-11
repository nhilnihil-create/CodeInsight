#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, R, rr;
  cin >> N >> R;
  if (N<10) {
    rr = R + 100*(10-N);
  }
  else {
    rr=R;
  }
  cout << rr << endl;
}