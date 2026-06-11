#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  for(int i=0; i<n; ++i){
    if(i%2 == 0 && s[i] == 'L') ok = false;
    else if(i%2 == 1 && s[i] == 'R') ok = false;
  }
  cout << (ok ? "Yes":"No") << endl;
}