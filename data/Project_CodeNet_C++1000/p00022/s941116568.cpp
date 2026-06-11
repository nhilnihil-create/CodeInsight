#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  int n, a[5000], ca;
  long long ans, sum;
  while(cin >> n, n){
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }

    ans = -1e5;
    for (int i = 0; i < n; i++){
      sum = 0;
      for (int j = i; j < n; j++){
        sum += a[j];
        ans = max(sum, ans);
      }
    }
    cout << ans << endl;
  }

  return 0;
}