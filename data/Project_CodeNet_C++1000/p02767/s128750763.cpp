#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 10000001;
  for (int p = 1; p <= 100; p++)
  {
    int suma = 0;
    for (int i = 0; i < n; i++)
      suma += (a[i] - p) * (a[i] - p);
    ans = min(suma, ans);
  }
  cout << ans << endl;
}