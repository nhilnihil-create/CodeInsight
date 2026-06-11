#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  if (s.size() % 2) s += " ";
  for (int i = 0; i < s.size(); ++i) {
    char want = 'h';
    if (i % 2) want = 'i';
    if (s[i] != want) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
