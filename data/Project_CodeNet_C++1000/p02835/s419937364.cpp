#include <bits/stdc++.h>
using namespace std;


int main() {
  int a1,a2,a3;
  
  cin >> a1 >> a2 >> a3;
  
  int total = a1+a2+a3;
  
  if(total < 22)
    cout << "win";
  
  else
    cout << "bust";
  
}
