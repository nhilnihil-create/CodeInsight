#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,r;
  
  cin >> n >> r;
  
  int total = 0;
  
  if(n>10)
    cout << r;
  
  else{
    total = r+(100*(10-n));
    cout << total;
  }
    
   
}