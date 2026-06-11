#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll a;
  string b;
  cin >> a >> b;
  int bb = (b[0]-'0') * 100 + (b[2]-'0') * 10 + (b[3]-'0');
  a *= bb;
  a /= 100;
  cout << a << endl;
}

