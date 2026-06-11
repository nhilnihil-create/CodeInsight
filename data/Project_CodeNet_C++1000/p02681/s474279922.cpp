#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  cin >> A >> B;
  int X = B.size();
  B.at(X - 1) = ' ';
  A = A + ' ';
  if(A == B) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
