#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
  {
    string si = to_string(i);
    if (si.size() % 2 != 0) cnt++;
  }
  cout << cnt << endl;
}