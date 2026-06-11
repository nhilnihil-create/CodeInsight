#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  string ans = "No";
  int num_doublet_occur = 0;
  while (N--)
  {
    int D1, D2;
    cin >> D1 >> D2;
    if (D1 == D2) num_doublet_occur++;
    else num_doublet_occur = 0;
    if (num_doublet_occur >= 3) ans = "Yes";
  }
  cout << ans;
}