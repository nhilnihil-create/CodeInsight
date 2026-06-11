#include <bits/stdc++.h>
using namespace std;

int main() {
  string T;
  cin >> T;
  for (int i = 0; i < T.size(); i++) {
    if (T.at(i) == '?') cout << 'D';
    else cout << T.at(i);
  }
  cout << endl;
}
