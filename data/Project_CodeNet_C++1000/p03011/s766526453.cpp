#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, M; 
  cin >> N >> X >> M;
  cout << N + M + X - max(N,max(M,X)) << endl;
 
}