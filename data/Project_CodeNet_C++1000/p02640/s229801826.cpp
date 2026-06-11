#include<bits/stdc++.h>
using namespace std;
int main() {
  int much, foot;
  cin >> much >> foot;
  if(much * 4 < foot) {
    cout << "No" << endl;
  }
  else if(much * 2 > foot) {
    cout << "No" << endl;
  }
  else if(foot % 2 != 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
  return 0;
}
