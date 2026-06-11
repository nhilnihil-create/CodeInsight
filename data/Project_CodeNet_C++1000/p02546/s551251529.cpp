#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  cin >> S;
  char& e = S.back();
  if (e == 's') {
    cout << S + "es" << endl;
  } else {
    cout << S + "s" << endl;
  }
}