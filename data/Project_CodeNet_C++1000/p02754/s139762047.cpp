#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  long long n,a,b;cin >> n >> a >> b;
 
  // compute 
  long long div;
  long long ans = 0;
  div = n / (a + b);
  if(a == 0){
    cout << "0" << endl;
    return 0;
  }
  if((n % (a + b)) / a == 0){
     ans = div * a + (n -(a + b) * div);    
  }else{
     ans = div * a + a;
  }
  
  // output  
  cout << ans << endl;
  
}