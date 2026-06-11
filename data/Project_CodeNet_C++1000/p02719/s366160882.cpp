#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n,k;
  cin >> n >> k;
  
  int64_t ans = n % k;
  if(ans < abs(ans - k)){
    cout << ans << endl;
  }else{
    cout << abs(ans - k) << endl;
  }
}