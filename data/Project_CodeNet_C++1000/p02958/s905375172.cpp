#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N, n;
  cin >> N;
  vector<int> p;
  for (int i = 0; i < N; i++)
  {
    cin >> n;
    p.push_back(n);
  }
  if (is_sorted(p.begin(), p.end()))
  {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (p[i] > p[j])
      {
        swap(p[i], p[j]);
        if (is_sorted(p.begin(), p.end()))
        {
          cout << "YES" << endl;
          return 0;
        }
        swap(p[i], p[j]);
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
