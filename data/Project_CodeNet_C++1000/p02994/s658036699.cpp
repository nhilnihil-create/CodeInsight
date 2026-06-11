#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int S=(N-1)*N/2+N*L;
  int m;
  if (L>0) {
    m=L;
  }
  else if (L<=0 && N+L-1>=0) {
    m=0;
  }
  else {
    m=N+L-1;
  }
  cout << S-m << endl;
}
