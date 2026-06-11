#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >> b;
  int outlet = 1;
  int plug = 0;
  while(outlet < b) {
    outlet--;
    outlet += a;
    plug++;
  }
  cout << plug << endl;
}