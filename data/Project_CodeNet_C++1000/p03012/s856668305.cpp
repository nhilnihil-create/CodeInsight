#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int total = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    total += a[i];
  }
  
  int x = total*0.5;
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += a[i];
    if(x <= sum) {
      if(sum-x > x-sum+a[i]) {
        sum -= a[i];
      }
      break;
    }
  }
  cout << abs(sum-(total-sum)) << endl;
  return 0;
}