#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  cin >> a;
  if(a=="SRS"||a=="RSR"||a=="SSR"||a=="RSS"){
    cout << "1" << endl;
  }
  else if(a=="RRS"||a=="SRR"){
    cout << "2" << endl;
  }
  else if(a=="RRR"){
    cout << "3" << endl;
  }
  else{
    cout << "0" << endl;
  }
}