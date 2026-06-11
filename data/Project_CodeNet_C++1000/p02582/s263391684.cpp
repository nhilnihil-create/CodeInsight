#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  if(S == "SSS"){
    cout << 0 << endl;
  }else if(S == "SSR" || S == "SRS" || S == "RSS" || S == "RSR"){
    cout << 1 << endl;
  }else if(S == "RRR"){
    cout << 3 << endl;
  }else{
    cout << 2 << endl;
  }
  return 0;
}
