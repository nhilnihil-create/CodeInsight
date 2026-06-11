#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int ans = 0;
  int p[n];
  for(int i = 1; i <= n; i++){
    cin >> p[i];
  }
  
  for(int i = 1; i <= n; i++){
    if(i != p[i]){
      ans++;
    }//if
  }
  if(ans > 2){
     cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
}