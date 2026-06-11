#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  
  int a[m];
  for(int i = 0; i < m; i++){
    cin >> a[i];
  }
  
  int ans = 0;
  for(int i = 0; i < m; i++){
    ans += a[i];
  }
  
  if(ans > n){
    cout << -1 << endl;
  }else{
    cout << n - ans << endl;
  }
}
