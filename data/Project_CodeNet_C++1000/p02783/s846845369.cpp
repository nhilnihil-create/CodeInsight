#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, a;
  cin >> h >> a;
  int c = h / a;
  h = h % a;
  if(1 <= h) {
    c++;
  }
  cout << c << endl;
}
