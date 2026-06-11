#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin >> n >> k;
  
  int x,y;
  int ans[n+1] = {0};
  for(int i = 1; i <= k; i++){
    cin >> x;
    for(int j = 1; j <= x; j++){
      cin >> y;
      ans[y]++;
    }
  }
  
  int cou = 0;
  for(int i = 1; i <= n; i++){
    if(ans[i] == 0){
      cou++;
    }
  }
  
  cout << cou << endl;
    
}