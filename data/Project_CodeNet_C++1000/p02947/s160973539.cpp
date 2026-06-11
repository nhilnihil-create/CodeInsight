#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

long long combi(long long num)
{
  return num * (num - 1) / 2;
}

int main()
{
  int N;
  cin >> N;

  std::unordered_map<string, int> m;
  rep(i, N)
  {
    string s;
    cin >> s;
    std::sort(s.begin(), s.end());
    m[s]++;
  }

  long long count = 0;
  for (const auto &e : m)
  {
    count += combi(e.second);
  }

  cout << count << endl;

  return 0;
}
