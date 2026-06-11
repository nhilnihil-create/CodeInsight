#include <bits/stdc++.h>
using namespace std;

int64_t attack(long long h) {
  if(h == 1) return 1;
  return attack(h/2)*2+1;
}

int main() {
  long long h;
  cin >> h;
  cout << attack(h) << endl;
}
