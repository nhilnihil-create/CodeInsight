#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  bool ok = true;
  int size = S.size();
  for (int i = 0; i < size; i++) { 
    if (S.at(i) != S.at(size - i - 1)) {
      ok = false;
    }
  }
  for (int i = 0; i < (size - 1) / 2; i++) { 
    if (S.at(i) != S.at((size - 1) / 2 - i - 1)) {
      ok = false;
    }
  }
  int j = 0;
  for (int i = (size + 3) / 2; i <= size; i++) { 
    if (S.at(i - 1) != S.at(size - j - 1)) {
      ok = false;
    }
    j++;
  } 
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}