#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  string b;
  cin >> b;
  std::string c(n * 2, 'a');
  for (int i = 0; i < n * 2; i++) {
    if (i % 2 == 0) {
      c.at(i) = a.at(i / 2);
    }
    else {
      c.at(i) = b.at((i - 1) / 2);
    }
  }
  cout << c << endl;
}