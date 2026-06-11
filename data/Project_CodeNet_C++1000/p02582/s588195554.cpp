#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string w;
    cin >> w;
  
  if(w == "SSS"){cout << '0' << endl;}
  else if(w == "SSR" || w == "RSS" || w == "SRS"|| w == "RSR"){cout << '1' << endl;}
  else if(w == "RRS" || w == "SRR"){cout << '2' << endl;}
  else {cout << '3' << endl;}
  
}