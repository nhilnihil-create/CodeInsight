#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int a, b, m=0;
  for (int i=1; i<=10000; i++) {
    a=i*1.08-i;
    b=i*1.1-i;
    if (a==A && b==B) {
      m=i;
      break;
    }
  }
  if (m==0) {m=-1;}
  cout << m << endl;
}
