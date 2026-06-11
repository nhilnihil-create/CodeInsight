#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  cin >> A;
  if(A.at(0) == A.at(1)) {
    cout << "Bad" << endl;
  }
   else if(A.at(2) == A.at(1)) {
    cout << "Bad" << endl;
  }
  else if(A.at(2) == A.at(3)) {
    cout << "Bad" << endl;
  }
  else {
    cout << "Good" << endl;
  }
}