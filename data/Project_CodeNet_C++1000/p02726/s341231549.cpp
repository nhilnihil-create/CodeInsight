#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--; y--;
  
  map<int,int> mp;
  
  for (int i=0; i<(n-1); i++) {
    for (int j=i+1; j<(n); j++) {
      int a = abs(i-j);
      int b = abs(i-x) + abs(j-y) + 1;
      int c = min(a,b);
      mp[c]++;
    }
  }
  
  for (int i=1; i<n; i++)
    cout << mp[i] << endl;
}