#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n;
  cin >> n;
  
  int64_t a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  int64_t zero = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == 0){
      zero++;
    }
  }//for
  if(zero > 0){
    cout << 0 << endl;
    return 0;
  }
  
  int64_t sum = 1;
  for(int i = 0; i < n; i++){
    if(a[i] <= 1000000000000000000/sum){
      sum *= a[i];
    }else{
      cout << -1 << endl;
      return 0;
    }
  }//for
  
  cout << sum << endl;
}