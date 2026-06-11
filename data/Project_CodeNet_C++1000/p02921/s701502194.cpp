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
  string S, T;
  cin >> S >> T;

  int count = 0;
  rep(i, S.size())
  {
    if (S[i] == T[i])
      count++;
  }
  cout << count << endl;

  return 0;
}
