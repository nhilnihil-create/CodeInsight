#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b;
  
  cin >> a >> b;
  
  int dis = abs(a-b);
  
  
  
  if(dis%2 == 0)
    cout << (a+b)/2;
  
  else{
    cout << "IMPOSSIBLE";
    return 0;
  }
    
  
}
