#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  vector<int> a;
  vector<int> b;
  vector<int> c;

  cin >> n;

  a.resize(n);
  b.resize(n);
  c.resize(n - 1);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    cin >> c[i];
  }

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += b[a[i]];
    if (i < n - 1 && a[i] + 1 == a[i + 1])
    {
      sum += c[a[i]];
    }
  }

  cout << sum << endl;
  return 0;
}