#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin >> a;
  int count = 0;
  for (char c : a){
    count += int(c)-48;
  }
  if (count%9==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}