#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int n;
  string s, s_abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin >> n >> s;
  for (int i = 0; i < s.length(); ++i)
  {
    cout << s_abc[s_abc.find(s[i]) + n];
  }
}
