#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = n / 500 * 1000;
  int y = n % 500 / 5 * 5;
  cout << x + y << endl;
}