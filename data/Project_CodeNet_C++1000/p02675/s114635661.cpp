#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string n;
  cin >> n;
  string ch = n.substr(n.size()-1,1);
  if(ch == "2" || ch == "4" ||
  ch == "5" || ch == "7" || ch == "9")
    cout << "hon" << endl;
  else if(ch == "0" || ch == "1" || 
  ch == "6" || ch == "8")
    cout << "pon" << endl;
  else if(ch == "3") cout << "bon" << endl;
}