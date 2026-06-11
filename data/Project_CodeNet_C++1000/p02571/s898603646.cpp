#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;

  int mi = 2000;
  for(int i = 0; i < s.size()-t.size()+1; i++) {
    int cnt = 0;
    int x = i;
    for(int j = 0; j < t.size(); j++) {
      if(s[i] != t[j]) cnt++;
      i++;
    }
    i = x;
    mi = min(mi, cnt);  
  }

  cout << mi << endl;
}
