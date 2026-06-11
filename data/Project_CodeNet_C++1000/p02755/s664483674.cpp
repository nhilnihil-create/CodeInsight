#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, ans;
  cin >> A >> B;
  ans = -1;
  
  for(int i=1; i<15000; i++){
    int a=i*8/100;
    int b=i*10/100;
    if(a==A && b==B){
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
    
}
