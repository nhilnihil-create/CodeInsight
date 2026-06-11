#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
  cin >> str;
  if(str.at(0) == str.at(1)) cout << "Bad";
  else if(str.at(1) == str.at(2)) cout << "Bad";
  else if(str.at(2) == str.at(3)) cout << "Bad";
  else cout << "Good";
    //
}
