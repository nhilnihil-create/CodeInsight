#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll X, Y = 100, Z = 0;
  cin >> X;
  while (Y < X) {
    Y += Y / 100;
    Z++;
  }
  cout << Z << endl;
}