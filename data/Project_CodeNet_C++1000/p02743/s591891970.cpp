#include <bits/stdc++.h>
using namespace std;


int main() {
  
  long long a, b, c;
  cin >> a >> b >> c;
  
  long long x;
  x =c-a-b;
  
  if(x<=0){
    cout << "No" << endl;
  }
  
  else if(x*x<=4*a*b){
    cout << "No" << endl;
  }
  
  else {
    cout << "Yes" << endl;
  }
  
  return 0;
}

