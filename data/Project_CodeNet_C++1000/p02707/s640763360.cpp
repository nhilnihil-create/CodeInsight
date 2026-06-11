#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> V(N,0);
  int A;
  for (int i=1; i<N; i++) {
    cin >> A;
    V[A-1]++;
  }
  for (int i=0; i<N; i++) {
    cout << V[i] << endl;
  }
}