#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string n;
  cin >> n;  

  int cnt = 0;
  for(int i = 1; i <= stoi(n); i++) {
    string s = to_string(i);
    if(s.size() % 2 != 0) cnt++;
    i = stoi(s);
  }  
  cout << cnt << endl;
}