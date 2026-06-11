#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  cout << string(N, 'x') << endl;
}