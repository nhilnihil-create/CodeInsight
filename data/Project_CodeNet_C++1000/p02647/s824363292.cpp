#include <iostream>
#include <vector>

using namespace std;

// 1次元累積和で解けるのか？
int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> a;
  a.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int p = 0; p < k; p++)
  {
    vector<int> b;
    b.resize(n);

    for (int i = 0; i < n; i++)
    {
      int l = max(0, i - a[i]);
      int r = min(n - 1, i + a[i]);

      b[l]++;
      if (r + 1 < n)
      {
        b[r + 1]--;
      }
    }

    for (int i = 1; i < n; i++)
    {
      b[i] += b[i - 1];
    }

    if (a == b)
    {
      break;
    }

    // 更新
    a = b;
  }

  for (int i = 0; i < n; i++)
  {
    cout << a[i] << endl;
  }

  return 0;
}