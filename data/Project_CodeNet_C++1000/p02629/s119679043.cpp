#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

string f(ll n) {
  if(n == 0) return "";
  n--;
  return f(n/26) + string(1,'a'+ n%26);
}

int main() {
  ll n;
  cin >> n;
  cout << f(n) << endl;
  return 0;
}