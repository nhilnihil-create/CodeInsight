#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int U=0;
  U+=((X/500)*1000);
  X %= 500;
  U+=((X/5)*5);
  cout << U << endl;
}