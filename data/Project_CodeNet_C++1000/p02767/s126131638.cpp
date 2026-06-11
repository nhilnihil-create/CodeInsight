#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int x[n];
  for (int i = 0; i < n; i++)
    cin >> x[i];
  
  sort(x, x+n);
  int beg = x[0], end = x[n-1];
  int ans;
  
  for (int i = 0; i < end-beg+1; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += pow((x[j]-(beg + i)), 2);
    }
    if (i == 0)
      ans = sum;
    else if (sum < ans)
      ans = sum;
  }
  cout << ans;
}