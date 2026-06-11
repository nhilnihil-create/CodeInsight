#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if (s == "SSS"){
    cout << 0 << endl;
  }
  else if (s == "RSS" || s == "SRS" || s == "SSR" || s == "RSR"){
    cout << 1 << endl;
  }
  else if (s == "RRR"){
    cout << 3 << endl;
  }
  else{
    cout << 2 << endl;
  }
}