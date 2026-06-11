#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int>a(M);
  vector<int>b(N+1,100);
  b.at(0) = 1;
  for (int i = 0; i < M; i++) {
    cin >> a.at(i);
    b.at(a.at(i)) = 0;
  }
  for (int i = 1; i < N+1; i++) {
    if (i == 1){
      if (b.at(i) != 0){
        b.at(1) = 1;
      }
    }
    else {
      if (b.at(i) != 0){
        b.at(i) = b.at(i-1) + b.at(i-2);
      }
    }
    b.at(i) %= 1000000007;
  }
  cout << b.at(N) << endl;
}
  

