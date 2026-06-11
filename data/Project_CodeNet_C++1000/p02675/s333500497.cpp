#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  char n = N.at(N.size()-1);
  if (n=='3') {
    cout << "bon" << endl;
  } else if (n=='0' || n=='1' || n=='6' || n=='8') {
    cout << "pon" << endl;
  } else {
    cout << "hon" << endl;
  }
  return 0;
}