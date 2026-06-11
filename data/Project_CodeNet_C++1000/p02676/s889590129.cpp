#include <iostream>
#include <string>

using namespace std;

int main() {
  int K;
  string s;
  cin >> K >> s;
  cout << s.substr(0, K);
  if (s.length() > K) cout << "...";
  cout << endl;
  return 0;
}
