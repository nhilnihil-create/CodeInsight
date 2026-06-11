#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int m, d;
  cin >> m >> d;
  
  int ans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= d; j++)
      if (i == (j / 10 >= 2 ? j / 10 : 1000) * (j % 10 >= 2 ? j % 10 : 1000)) ans++;
  
  cout << ans << endl;
}