#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,d;
  cin >> n >> d;
  
  int x = 2 * d + 1;
  int ans = 0;
  if(n % x == 0){
    ans = n / x;
  }else{
    ans = n / x + 1;
  }
  
  cout << ans << endl;
}