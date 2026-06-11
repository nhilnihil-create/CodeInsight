#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void primeFactorize(vector<int> &ans, int n)
{
  for (int i = 2; i <= (int)sqrt(n); i++)
  {
    if (n % i == 0)
    {
      ans.push_back(i);
      primeFactorize(ans, n / i);
      return;
    }
  }
  ans.push_back(n);
}

int main()
{
  int n;
  cin >> n;
  vector<int> ans;
  primeFactorize(ans, n);
  cout << n << ":";
  rep(i, ans.size())
  {
    cout << " " << ans.at(i);
  }
  cout << endl;
}
