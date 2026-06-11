#include<iostream>
using namespace std;
int main() {
  long X;
  cin >> X;
  int ans = 0;
  for (long x = 100; x < X; x += x / 100, ans++);
  cout << ans << endl;
}