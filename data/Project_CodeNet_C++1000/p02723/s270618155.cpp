#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  string s;
  cin >> s;
  cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
  return 0;
}
