#include <bits/stdc++.h>
using namespace std;
int main() {
  char a;
  cin >> a;
  if ('A'<=a&&a<='Z') {
    a = 'A';
  } else {
    a = 'a';
  }
  cout << a << endl;
}