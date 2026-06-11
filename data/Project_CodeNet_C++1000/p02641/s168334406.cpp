#include <bits/stdc++.h>
using namespace std;

int main()
{
  int y,n;
  cin >> y >> n;
  
  int p[n];
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }

  int x[101] = {0};
  for(int i = 0; i < n; i++){
    x[p[i]]++;
  }
  
  int maxze = 101;
  int ans = 101;
  for(int i = 0; i <= 101; i++){
    if( (x[i] == 0) && (abs(i - y) < maxze) ){
      maxze = abs(i - y);
      ans = i;
    }
  }
  
  if(n == 0){
    ans = y;
  }
  if(maxze >= abs(y + 1)){
    ans = -1;
  }
  

  
  cout << ans << endl;
  
}