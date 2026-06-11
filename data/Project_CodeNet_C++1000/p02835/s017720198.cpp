#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  if(a1 + a2 + a3 >= 22) cout << "bust" << endl;
  else cout << "win" << endl;
}