#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  
  int total = 0;
  
  if(k <= a){
    total = 1 * k;
  }
  else if(a < k){
    total = total + 1 * a;
    int l = k - a;
    if(b >= l){
      
    }
    else if(b < l){
      int m;
      m = l - b;
      total = total + -1 * m;
    }
    
  }
  
  cout << total << endl;
  
  
}

