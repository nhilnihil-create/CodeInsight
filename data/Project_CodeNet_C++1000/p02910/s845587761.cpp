#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  bool good = true;
  for(int i = 0; i < s.size();i++){
    if(i%2==0){
      if(!(s.at(i)=='R' || s.at(i)=='U' || s.at(i)=='D'))
        good = false;
    } else {
      if(!(s.at(i)=='L' || s.at(i)=='U' || s.at(i)=='D'))
        good = false;
    }
  }
  if(good) cout << "Yes" << endl;
  else cout << "No" << endl;
}
