#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  int ans;
  cin >> A >> B;
  for(int i = 1; i < 4; i++){
    if(A != i && B != i){
      ans = i;
    }
  }
  cout << ans << endl;
  }
    