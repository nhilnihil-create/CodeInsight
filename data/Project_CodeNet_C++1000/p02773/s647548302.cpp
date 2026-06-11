#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string s;
  int num = 0;
  map<string, int> m;
  for(int i=0; i<n; i++) {
    cin >> s;
    m[s]++;
    num = max(num, m[s]);
  }
  
  for(auto p : m) if(p.second==num) cout << p.first << endl;
  return 0;
}