#include<iostream>
using namespace std;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  for (int i = 1; k * i <= b; i++) {
    int t = k * i;
    if (t >= a && t <= b) return cout << "OK" << endl, 0;
  }
  cout << "NG" << endl;
}