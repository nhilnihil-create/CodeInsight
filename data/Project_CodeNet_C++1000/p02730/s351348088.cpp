#include <bits/stdc++.h>
using namespace std;
int judge(string s) {
  int r = s.size()/2;
  for(int i=0; i<r; i++) {
    if(s.at(i) != s.at(s.length()-1-i)) {
      return false;
    }
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  if(!judge(s)) {
    cout << "No" << endl;
    return 0;
  }
  int p = (s.size()-1)/2;
  string t = s.substr(0,p);
  if(!judge(t)) {
    cout << "No" << endl;
    return 0;
  }
  p = (s.size()+3)/2;
  p -= 1;
  string u = s.substr(p,s.back());
  if(!judge(u)) {
    cout << "Nou" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}