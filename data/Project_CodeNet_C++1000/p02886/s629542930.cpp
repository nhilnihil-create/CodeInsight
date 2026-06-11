#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) {
    cin >> v[i];
  }
  
  int sum = 0;
  for(int i=0; i<n-1; i++) {
    for(int j=1; j<n; j++) {
      if (i<j) { 
        sum += v[i]*v[j];
      }
    }
  }
  cout << sum << endl;
}