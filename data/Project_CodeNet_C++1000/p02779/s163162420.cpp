#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, string>;

int main() {
  int N, A;
  cin >> N;
  set<int> S;
  for (int i=0; i<N; i++) {
    cin >> A;
    S.insert(A);
  }
  if ((int)S.size()==N) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}