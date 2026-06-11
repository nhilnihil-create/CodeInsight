#include <bits/stdc++.h>
using namespace std;

const long long int MAX = 1e18;

int main() {
  int n = 0;
  cin >> n;
  long long int a,ans = 1;
  bool over = false;
  

  for(int i = 0; i < n; i++){
    cin >> a;
    
    if(a == 0){
      ans = 0;
      break;
    }
    if (over) continue;
	if(a <= MAX/ans){
      ans *= a;
    }
    else {
      ans = -1;
      over = true;
    }
  }
        
    
    
  cout << ans << endl;
  return 0;
  
  
}
