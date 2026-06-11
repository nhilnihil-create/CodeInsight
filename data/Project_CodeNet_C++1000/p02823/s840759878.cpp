#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B;
  cin >> N >> A >> B;
  if (abs(A - B) % 2 == 0)
  {
    cout << abs(A - B) / 2 << endl;
  }
  else
  {
    int64_t a = ((N - A) + (N - B) + 1) / 2;
    int64_t b = (A - 1 + B - 1 + 1) / 2;
    cout << min(a, b) << endl;
  }
}