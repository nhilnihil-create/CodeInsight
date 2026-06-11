#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin >> n >> k;
  
  int h[n];
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> h[i];
    if(h[i] >= k){
      ans++;
    }
  }
  
  cout << ans << endl;
}