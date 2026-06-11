#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  cout << (s[0]=='S'?"Cloudy":s[0]=='C'?"Rainy":"Sunny");
}