// ABC_136_B
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;


  int counter = 0;
  for (int i = 1; i <= n; ++i) {
    string tmp = to_string(i);
    if (tmp.size() % 2 == 1) ++counter;
    else continue;
  }

  cout << counter << "\n";

  return 0;
}