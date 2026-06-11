#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const long long MOD = 1000000007;

vector<int> memo(100001);

void create_memo()
{
  memo[0] = 1;
  memo[1] = 1;

  for (int i = 2; i < memo.size(); i++)
  {
    memo[i] = memo[i - 1] + memo[i - 2];
    memo[i] %= MOD;
  }
}

int main()
{
  int N, M;
  cin >> N >> M;

  create_memo();

  vector<long long> group;
  int before = 0;
  rep(i, M)
  {
    int a;
    cin >> a;
    group.emplace_back(a - before);
    before = a + 1;
    if (i == M - 1)
    {
      group.emplace_back(N - a);
    }
  }

  if (M == 0)
  {
    group.emplace_back(N + 1);
  }

  long long result = 1;
  rep(i, group.size())
  {
    if (group[i] == 0)
    {
      cout << 0 << endl;
      return 0;
    }
    else
    {
      result *= memo[group[i] - 1];
      result %= MOD;
    }
  }

  cout << result << endl;

  return 0;
}
