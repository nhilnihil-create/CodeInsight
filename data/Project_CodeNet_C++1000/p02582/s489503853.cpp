#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  if(S == "SSS"){cout << 0 << endl;}
  else if(S == "SSR"){cout << 1 << endl;}
  else if(S == "SRS"){cout << 1 << endl;}
  else if(S == "RSS"){cout << 1 << endl;}
  else if(S == "RRS"){cout << 2 << endl;}
  else if(S == "RSR"){cout << 1 << endl;}
  else if(S == "SRR"){cout << 2 << endl;}
  else{cout << 3 << endl;}
}
