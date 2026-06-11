#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, t;
  cin >> a >> b;
  t = min(a, b);
  if(t == a) {
    for(int i = 0;i < b;++i) {
      cout << a;
    }
  } else {
    for(int i = 0;i < a;++i) {
      cout << b;
    }
  }
}