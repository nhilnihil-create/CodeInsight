#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin >> a;
  int x = a.size();
  for(int i = 0;i < x;++i) {
    a.at(i) = 'x';
  }
  cout << a << endl;
}