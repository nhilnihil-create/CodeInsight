#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int m = n % 10;
  if (m==2 || m==4 || m==5 || m==7 || m==9) {
    cout << "hon" << endl;
  }
  else if (m==3) {
    cout << "bon" << endl;
  }
  else
    cout << "pon" << endl;
}