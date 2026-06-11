#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i)
  {
    if (i % 2 == 0 && s[i] != 'R' && s[i] != 'U' && s[i] != 'D')
    {
      cout << "No";
      return 0;
    }
    else if (i % 2 != 0 && s[i] != 'L' && s[i] != 'U' && s[i] != 'D')
    {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
