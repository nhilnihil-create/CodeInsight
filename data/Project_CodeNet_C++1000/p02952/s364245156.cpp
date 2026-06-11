#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int ans = 0;
  for (int i=1 ; i<=n ; i++){
    if (i/10 == 0)
      ans++;
    else if (i/100 != 0 && i/1000 == 0)
      ans++;
    else if (i/10000 != 0 && i/100000 == 0)
      ans++;
  }
  
  cout << ans << endl;
}