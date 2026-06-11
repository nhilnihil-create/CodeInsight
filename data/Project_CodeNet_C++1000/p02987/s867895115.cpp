#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  std::sort(S.begin(), S.end());
  if (S[0] == S[1] && S[2] == S[3] && S[1] != S[2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
