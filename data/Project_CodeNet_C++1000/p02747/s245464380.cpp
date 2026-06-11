#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  bool chk = true;
  
  cin >> str;
  
  if(str.size() % 2 == 1) chk = false;
  
  for(int i = 0; i < str.size() / 2; i=i+2){
    if(str.substr(i,2) != "hi") chk = false;
  }
  
  if(chk == true) cout << "Yes";
  else cout << "No";
}
