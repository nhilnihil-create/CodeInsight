#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;

  string A, B;
  for (int i = 0; i < b; i++)
  {
    A += to_string(a);
  }
  for (int i = 0; i < a; i++)
  {
    B += to_string(b);
  }
  cout << min(A, B) << endl;
}
