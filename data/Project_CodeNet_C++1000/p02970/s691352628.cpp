#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  int ans = 0;
  
  for(int i=0;i<30;i++){
    if((2*d+1)*i>=n){
      ans = i;
      break;
    }
  }
    
    cout << ans << endl;
  }
    