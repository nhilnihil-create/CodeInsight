#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

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
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int gcd_ = std::gcd(A[0], A[1]);
  rep(i, N)
  {
    gcd_ = std::gcd(gcd_, A[i]);
  }

  if (gcd_ != 1)
  {
    cout << "not coprime" << endl;
    return 0;
  }

  int MX = 1000000;

  std::unordered_set<int> p;
  rep(i, N)
  {
    int tmp = A[i];
    vector<int> v;
    for (int j = 2; j * j <= A[i]; j++) {
      if (tmp % j == 0) {
        tmp /= j;
        if (p.find(j) != p.end())
        {
          cout << "setwise coprime" << endl;
          return 0;
        }
        else
        {
          v.emplace_back(j);
        }
      }
      if (tmp == 1) break;
    }
    
    if (tmp != 1) {
      if (p.find(tmp) != p.end())
        {
          cout << "setwise coprime" << endl;
          return 0;
        }

      v.emplace_back(tmp);
    }

    for (const auto e : v)
    {
      p.insert(e);
    }
  }

  cout << "pairwise coprime" << endl;

  return 0;
}
