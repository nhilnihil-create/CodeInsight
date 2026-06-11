#include<bits/stdc++.h>
using namespace std;
int main() {
  int target, n;
  cin >> target >> n;
  
  if(n == 0) {
    cout << target << endl;
    return 0;
  }
  
  vector<int> ex(n);
  
  for(int i=0;i<n;i++) {
    cin >> ex.at(i);
  }
  
  vector<int> dx(202);
  
  for(int i=0;i<n;i++) {
    dx.at(ex.at(i)) = 1;
  }
  
  for(int i=0;i<101;i++) {
    if(dx.at(target - i) == 0) {
      cout << target - i << endl;
      break;
    }
    if(dx.at(target + i) == 0) {
      cout << target + i << endl;
      break;
    }
  }
  return 0;
}
  