#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n;
  cin >> a >> b;
  n = (b-1)/(a-1);
  if ((b-1)%(a-1)!=0) n++;
  cout << n << endl;
}
