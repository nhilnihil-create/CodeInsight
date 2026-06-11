#include <iostream>
#include <string>

using namespace std;

int main() {
  string s = "Sunny", c = "Cloudy", r = "Rainy", in, res;
  cin >> in;
  if (in == s)
    res = c;
  else if (in == c)
    res = r;
  else if (in == r)
    res = s;

  cout << res << endl;

  return 0;
}
