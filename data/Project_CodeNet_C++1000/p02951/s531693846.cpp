#include<iostream>
using namespace std;

int A, B, C;

int main() {
  cin >> A >> B >> C;
  cout << max(0, C-A+B) << endl;
}