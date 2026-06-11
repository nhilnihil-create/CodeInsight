#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m; cin >> n >> m;
  int a[n], sum = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  double ppty = sum / double(m*4);
  int cnt = 0;
  for(int i = 0; i < n; i++)
    if(a[i] >= ppty)
      cnt++;
  if(cnt >= m)
    cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
