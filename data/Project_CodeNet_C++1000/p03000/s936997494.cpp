#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  int sum = 0;
  int count = 1;
  for(int i=0; i<n; i++) {
    sum += a[i];
    if(sum > x) break;
    count++;
  }
  cout << count << endl;
  return 0;
}