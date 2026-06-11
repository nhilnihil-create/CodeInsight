#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int former;
  cin >> former;
  former--;
  bool check = true;
  for(int i = 1; i < N; i++) {
    int h;
    cin >> h;
    if(h > former) {
      former = h - 1;
    }
    else if(h == former) {
      former = h;
    }
    else {
      check = false;
      break;
    }
  }
  if(check) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }  
}