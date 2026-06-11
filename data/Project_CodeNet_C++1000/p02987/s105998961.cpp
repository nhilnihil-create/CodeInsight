#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  cin >> A;
  if((A.at(0) == A.at(1)) && (A.at(1) == A.at(2))) {
    cout << "No" << endl;
  }
  else if(A.at(0) == A.at(1)) {
    if(A.at(2) == A.at(3)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else if(A.at(0) == A.at(2)) {
    if(A.at(1) == A.at(3)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else if(A.at(0) == A.at(3)) {
    if(A.at(1) == A.at(2)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}
