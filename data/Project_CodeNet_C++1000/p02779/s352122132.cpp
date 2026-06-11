#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  unordered_set<int> b;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    b.insert(a);
  }
  
  if(n==b.size()) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0; 
}