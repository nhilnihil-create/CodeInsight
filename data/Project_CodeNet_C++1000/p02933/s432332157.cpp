#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int a;
  cin >> a;
  string s;
  cin >> s;

  if (a < 3200)
  {
    cout << "red" << endl;
  }
  else
  {
    cout << s << endl;
  }

  return 0;
}
