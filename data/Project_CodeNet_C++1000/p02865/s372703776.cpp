#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, cnt = 0;
  cin >> N;
  for (int i = 1; i <= N / 2; i++)
  {
    if (i != N - i)
      cnt++;
  }
  cout << cnt << endl;
}