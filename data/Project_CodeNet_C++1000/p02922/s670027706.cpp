#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, X, count;
  cin >> A >> B;
  for (X = 1, count = 0; X < B; count++, X--){
    X += A;
  };
  cout << count << endl;
}
