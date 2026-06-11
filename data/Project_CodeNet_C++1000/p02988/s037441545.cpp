#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  int count = 0;
  for(int i=0; i<n-2; i++) {
    if(a[i] < a[i+1] && a[i+1] < a[i+2]) count++;
    else if(a[i] > a[i+1] && a[i+1] > a[i+2]) count++;
  }
  cout << count << endl;
  return 0;
}