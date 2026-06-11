#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long A;
  double B;

  cin >> A >> B;

  long long ans = (A * (long long)(B * 100 + 0.00001)) / 100;

  cout << ans << endl;
}
