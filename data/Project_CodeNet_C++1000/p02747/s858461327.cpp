#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int len = s.length();
  cout << (len % 2 == 0 && s == string("hihihihihi", len) ? "Yes" : "No") << endl;
}
