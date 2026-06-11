#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  string ans = "";
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
    if (a.at(i) % 2 == 0 && (a.at(i) % 3 != 0 && a.at(i) % 5 != 0))
    {
      ans = "DENIED";
    }
  }
  if (ans == "")
  {
    ans = "APPROVED";
  }
  cout << ans << endl;
}