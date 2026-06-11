#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s;
  cin >> s;
  int p = s.size() - 1;
  int x = 0;
  int total = 0;
  while(1) {
    int t = p - x;
    if(s.at(x) != s.at(t)) total++;
    x++;
    if(x == (p + 1) ) break;
  }
  
  cout << total / 2 << endl;
  
  
}

