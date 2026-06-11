#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if(s.at(0)==s.at(1)){
    if(s.at(2)==s.at(3)&&s.at(1)!=s.at(2)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else if(s.at(0)==s.at(2)){
    if(s.at(1)==s.at(3)&&s.at(1)!=s.at(2)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else if(s.at(0)==s.at(3)){
    if(s.at(1)==s.at(2)&&s.at(0)!=s.at(2)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}