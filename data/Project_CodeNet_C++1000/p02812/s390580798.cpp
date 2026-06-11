#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, kaunto;
  cin >> a;
  string b;
  cin >> b;
  kaunto = 0;
  for (int i = 0; i < a - 2; i++) {
    if (b.at(i) == 'A' && b.at(i + 1) == 'B' && b.at(i + 2) == 'C') {
      kaunto++;
    }
  }
  cout << kaunto << endl;
}