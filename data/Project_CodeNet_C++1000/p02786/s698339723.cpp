#include<bits/stdc++.h>
using namespace std;
int main() {
  long long h, pro2 = 1; cin >> h;
  while(pro2 <= h) {
    pro2 *= 2;
  }
  cout << pro2 -1 << endl;
}