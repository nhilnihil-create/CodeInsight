#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int r;
  cin >> n;
  
  if(n % 1000 == 0){
     cout << 0 << endl;
  }else{
    r = 1000 - (n % 1000); 
    cout << r << endl;
  }
}