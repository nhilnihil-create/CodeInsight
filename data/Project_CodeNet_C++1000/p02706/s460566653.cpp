#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, x;
  cin >> N >> M;
  for (int i=0; i<M; i++){
    cin >> x;
    N -= x;
  }
  if (N<0)
    cout << "-1" << endl;
  else
    cout << N << endl;
}
