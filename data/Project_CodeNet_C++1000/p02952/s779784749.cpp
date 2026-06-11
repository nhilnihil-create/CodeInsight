#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int ans = 0;
  for(int i = 1; i < N + 1; ++i)
  {
    string str = std::to_string(i);
    int keta = str.size();
    if((keta % 2) == 1)
    {
      ++ans;
    }
  }
  cout << ans << endl;
}