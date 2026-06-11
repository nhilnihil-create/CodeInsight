#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  set<int> S = {1, 2, 3};
  S.erase(a);
  S.erase(b);
  cout << *S.begin() << endl;
}