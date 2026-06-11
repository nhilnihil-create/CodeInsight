#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N;
  N=S.size();
  bool H=false;
  bool I=false;

  for (int i=0; i<N; i++) {
    if (i%2==0) {
      if (S.at(i)=='h') {
        H = true;
      }
      else {
        H=false;
        break;
      }
    }
    if (i%2==1) {
      if (S.at(i)=='i') {
        I = true;
      }
      else {
        I=false;
        break;
      }
    }
  }
  if (N%2==0) {
  if (H==true && I==true) {
  cout << "Yes" << endl;
  }
  else {
  cout << "No" << endl;
  }
  }
  else if(N%2==1) {
    cout << "No" << endl;
  }
}