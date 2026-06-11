#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,x,t;
  cin >> n >> x >> t;
  
  int c = 0;
  
  if(n % x != 0){
    c= (n / x + 1)*t;
  }else{
    c= (n / x)*t;
  }
  cout << c << endl;
  
}