#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  int YUNI;
  cin >> a;
  
  size_t KYR = a.length();
  
  while(YUNI < KYR){
    if(a.at(YUNI) == '?'){
      a.at(YUNI) = 'D';
    }
    YUNI ++;
  }
    
  cout << a << endl;
  
}
  