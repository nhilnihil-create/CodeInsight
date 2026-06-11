#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool a = true,b = true,c = true;
  for(int i=0;i<n/2;i++){
    if(s.at(i) != s.at(n-1-i))
      a = false;
  }
  for(int i=0;i<n/4;i++){
    if(s.at(i) != s.at(n/2-1-i))
      b = false;
  }
  for(int i=0;i<n/4;i++){
    if(s.at(n-1-i) != s.at(n/2+1+i))
      c = false;
  }
  if(a && b && c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}