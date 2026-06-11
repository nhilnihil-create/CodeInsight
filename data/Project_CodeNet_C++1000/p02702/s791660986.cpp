#include <bits/stdc++.h>
using namespace std;

const int mod = 2019;
string s;
int main() {
  cin >> s;
  int n = s.size();
  
  map<int, int> mp;
  int curr = 0;
  int base = 1;
  mp[0] = 1;
  
  long sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    curr = (curr + base * (long)(s[i] - '0')) % mod;
    base = base * 10 % mod;
    sum += mp[curr];
    ++mp[curr];
  }
  cout << sum << endl;
}