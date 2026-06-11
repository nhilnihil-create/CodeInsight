#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> w(n);
  int sum = 0;
  rep(i, n) 
  {
    cin >> w.at(i);
    sum += w.at(i);
  }

  int mini = sum;
  int prefix_sum = 0;
  for (int i = 0; i < n; i++)
  {
    prefix_sum += w.at(i);
    mini = min(mini, abs(prefix_sum - (sum - prefix_sum)));
  }

  cout << mini << endl;

  

  return 0;
}