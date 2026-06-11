#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  int c=0;
  cin >> a >> b;
  for (int i=0; i<a.length(); i++) {
    if (a.at(i) == b.at(i)) c++;
  }
  cout << c << endl;
}
