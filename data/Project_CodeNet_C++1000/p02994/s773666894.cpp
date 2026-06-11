#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, l;
  cin >> n >> l;

  int sum = 0;

  vector<int> apple(n);
  rep(i, n)
  {
    apple.at(i) = l + i;
    sum += apple.at(i);
    // cout << apple.at(i) << endl;
  }

  // cout << sum;

  int ans = 100000;

  for (int i = 0; i < n; i++)
  {
    int tmp = sum - apple.at(i);
    ans = min(abs(tmp - sum), ans);
  }

  rep(i, n)
  {
    if (ans == abs(apple.at(i)))
    {
      ans = i;
      break;
    }
  }
  cout << sum - apple.at(ans);
}
