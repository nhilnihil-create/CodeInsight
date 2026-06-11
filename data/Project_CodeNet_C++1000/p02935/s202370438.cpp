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
  int N;
  cin >> N;
  vector<long double> v(N);
  rep(i, N) cin >> v[i];

  std::sort(v.begin(), v.end());
  long double num = v[0];
  for (int i = 1; i < v.size(); i++)
  {
    num = (num + v[i]) / 2;
  }

  cout << num << endl;

  return 0;
}
