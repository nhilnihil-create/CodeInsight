#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  vector<int> b(a);
  for (int i = 0; i < a; i++) {
    cin >> b.at(i);
  }
  int kaunto = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a; j++) {
      if (i != j) {
      kaunto += b.at(i) * b.at(j);
      }
    }
  }
  cout << kaunto / 2 << endl;
}