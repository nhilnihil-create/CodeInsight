#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;

  if (str.size() % 2 == 0) {
    for (int i = 0; i < str.size() - 1; i = i + 2) {
      if (str[i] != 'h' || str[i + 1] != 'i') {
        cout << "No" << endl;
        return 0;
      }
    }
  } else {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}