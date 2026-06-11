#include <bits/stdc++.h>
using namespace std;

long n;
int main() {
  cin >> n;
  map<long, long> mp;
  long sum = 0;
  for (int i = 0; i < n; ++i) {
    long a;
    cin >> a;
    sum += mp[i - a];
    ++mp[i + a];
  }
  cout << sum << endl;
}