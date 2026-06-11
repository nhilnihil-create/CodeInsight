#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> a(n, vector<int>(d));
  for(int i=0; i<n; i++) {
    for(int j=0; j<d; j++) {
      cin >> a[i][j];
    }
  }
  
  int sum = 0;
  int count = 0;
  for(int i=0; i<n-1; i++) {
    for(int j=1; j<n; j++) {
      if(i<j) {
        for(int k=0; k<d; k++) {
          sum += abs(a[i][k]-a[j][k])*abs(a[i][k]-a[j][k]);
          if(k==d-1) {
            if(int(sqrt(sum))*int(sqrt(sum))==sum) {
              count++;
              sum = 0;
            }
            else sum = 0;
          }
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}