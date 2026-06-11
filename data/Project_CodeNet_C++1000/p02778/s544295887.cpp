#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<char>a(s.size());
  for(int i=0;i<s.size();i++){
    a.at(i)='x';
  }
  for(int i=0;i<s.size();i++){
    cout << a.at(i);
  }
}

