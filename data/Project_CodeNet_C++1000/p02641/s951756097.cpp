#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int x, n,p[200];
  cin >> x >> n;  
  for(int i = 0; i < n; i++)
    cin >> p[i];
  
  if(n == 0) {
    cout << x << endl;
    return 0;
  }

  bool flags = 0, flagt = 0;
  for(int i = 0; ; i++) {
    int s = x - i;
    int t = x + i;
    for(int j = 0; j < n; j++) {
      if(s == p[j]) {
        flags = 0; break;
      } else flags = 1;
    }
    for(int j = 0; j < n; j++) {
      if(t == p[j]) {
        flagt = 0; break;
      } else flagt = 1;
    }
    if(flags == 1) {
      cout << s << endl; return 0;
    }
    else if(flagt == 1) {
      cout << t << endl; return 0;
    }
  }
}