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
  string S;
  cin >> S;

  rep(i, 3)
  {
    if (S[i] == S[i + 1])
    {
      cout << "Bad" << endl;
      return 0;
    }
  }

  cout << "Good" << endl;

  return 0;
}
