#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;
  
  int cnt = 0;
  for(int i = 0; i < s.size(); i++) cnt++;
  
  if(cnt <= k) {
    cout << s << endl;
    return 0;
  }
  for(int j = 0; j < k; j++) cout << s.at(j);
  cout << "..." << endl;
}