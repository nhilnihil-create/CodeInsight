#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  if(n<=9){
    cout << n << endl;
  }
  else if(n<=99){
    cout << 9 << endl;
  }
  else if(n<=999){
    cout << 9 + (n-100+1) << endl;
  }
  else if(n<=9999){
    cout << 9 + (999-100+1) << endl;
  }
  else if(n<=99999){
    cout << 9 + (999-100+1) + (n-10000+1) << endl;
  }
  else{
    cout << 9 + (999-100+1) + (99999-10000+1) << endl;
  }
  
}