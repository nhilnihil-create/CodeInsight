#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  string s;
  cin >> s;
  bool ok = true;
  for (int i = 0;i < s.size();i++) {
    if (i%2==0) {
      if (s.at(i) != 'h') ok = false;
    }
    else {
      if (s.at(i) != 'i') ok = false;
    }
  }
  if (s.size() % 2 == 1) ok = false;
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}

