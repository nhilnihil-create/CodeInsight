#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;
  cin >> n >> x;
  
  int l[n];
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }
  
  int ans = 1;
  int total = 0;
  for(int i = 0; i < n; i++){
    total += l[i];
    if(total <= x){
      ans++;
    }
  }
  
  cout << ans << endl;
}