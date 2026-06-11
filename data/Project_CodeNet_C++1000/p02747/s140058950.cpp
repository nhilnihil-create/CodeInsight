#include <bits/stdc++.h>
using namespace std;

int main() {
  bool    f = true;
  string  s;
  cin >> s;
  if (s.size() % 2 == 1) {
    f = false;
  } else {
    for(int i=0;i<s.size();i+=2) {
      if (s.at(i)!='h') f = false;
      if (s.at(i+1)!='i') f = false;
    }
  }
  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;
}
