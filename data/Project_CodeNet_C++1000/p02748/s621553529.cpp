#include <bits/stdc++.h>
using namespace std;

int main()
{
  long A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  int a_min = 100000001, b_min = 100000001;
  for (int i = 0; i < A; i++)
  {
    cin >> a[i];
    a_min = min(a[i], a_min);
  }
  for (int i = 0; i < B; i++)
  {
    cin >> b[i];
    b_min = min(b[i], b_min);
  }
  int min_value = a_min + b_min;
  for (int i = 0; i < M; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    min_value = min(min_value, a[x-1] + b[y-1] - c);
  }
  cout << min_value << endl;
}