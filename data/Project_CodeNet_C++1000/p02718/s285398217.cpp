#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  
  int a[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(a[i] * (4*m) >= sum){
      ans++;
    }
  }
  
  if(ans >= m){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
    
}