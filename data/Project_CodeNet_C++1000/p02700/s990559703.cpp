#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  while(1) {
    c -= b;
    if(c <= 0) {
      cout << "Yes";
      break;
    }
    a -= d;
    if(a <= 0) {
      cout << "No";
      break;
    }
  } 
}