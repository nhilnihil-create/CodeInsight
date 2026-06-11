#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,d;
  cin >> n >> d;
  
  int x[n],y[n];
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    double dist = hypot(x[i],y[i]);
    if(dist <= d){
      ans++;
    }
  }
  
  cout << ans << endl;
}
