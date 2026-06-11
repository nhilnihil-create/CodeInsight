#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,d;
  cin >> n >> d;
  
  int x[n][d];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < d; j++){
      cin >> x[i][j];
    }
  }
  
  long double sum = 0;
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = 0; k < d; k++){
        sum += (long double)(abs(x[i][k] - x[j][k]) * abs(x[i][k] - x[j][k]));
      }//for
      sum = sqrt(sum);
      if(floor(sum) == ceil(sum)){
         ans++;
      }//if
      sum = 0;
    }//for
   
  }//for
  
  cout << ans << endl;
}