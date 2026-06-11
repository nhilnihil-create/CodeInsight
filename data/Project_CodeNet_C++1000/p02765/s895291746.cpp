#include <bits/stdc++.h>
using namespace std;

int main() {
  int e,z,L;
  cin >> e >> z;
  if(e >= 10){
    cout << z <<endl;
    return 0;
  }
  else{
    cout << 100 * (10 - e) + z <<endl;
  }
}