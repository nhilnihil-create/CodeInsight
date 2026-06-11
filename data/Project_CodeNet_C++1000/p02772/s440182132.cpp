#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  vector<int> b(a);
  for (int i = 0; i < a; i++) {
    cin >> b.at(i);
  }
  bool c = true;
  int kauntoa = 0;
  int kauntob = 0;
  for (int i = 0; i < a; i++) {
    if (b.at(i) % 2 == 0) {
      kauntoa++;
    }
  }
  vector<int> d(kauntoa);
  for (int i = 0; i < a; i++) {
    if (b.at(i) % 2 == 0) {
      d.at(kauntob) = b.at(i);
      kauntob++;
    }
  }
  for (int i = 0; i < kauntoa; i++) {
    if (d.at(i) % 3 != 0 && d.at(i) % 5 != 0) {
      c = false;
      cout << "DENIED" << endl;
      break;
    }
  }
  if (c) {
    cout << "APPROVED" << endl;
  }
}