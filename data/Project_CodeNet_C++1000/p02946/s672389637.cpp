#include<bits/stdc++.h>
using namespace std;

int main(){
 
  long long K, X, i, Min, Max;
  cin >> K >> X;
  
  Min = max(X - K, -1000000ll);
  Max = min(X + K, 1000000ll);
    
  for(i = Min + 1; i < Max; i++){
    cout << i << " ";
  }
  cout << endl;
  return 0;
}