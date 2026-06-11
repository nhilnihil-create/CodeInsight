#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string s;
  map<string, int> m;
  for(int i=0; i<n; i++) {
    cin >> s;
    m[s]++;
  }
  
  int num = 0;
  for(auto p : m) num = max(num, p.second);
  for(auto p : m) if(p.second == num) cout << p.first << endl;
  return 0;
}