#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int x[n];
  int s = 101,g = -1;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    if(x[i] < s){
      s = x[i];
    }else if(x[i] > g){
      g = x[i];
    }
  }
  
  int64_t ans = 0,minans = 100000000;
  for(int i = s; i <= g; i++){
    for(int j = 0; j < n; j++){
      ans += abs(i - x[j]) * abs(i - x[j]);
    }//for
    if(ans < minans){
      minans = ans;
    }
    ans = 0;
  }//for
  
  if(n == 1){
    minans = 0;
  }
  
  cout << minans << endl;
  
}