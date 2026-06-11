#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int count = 0;
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r.at(i);
    
    if (r.at(i) % 2 == 1 && (i+1) % 2 == 1) {
      count++;
    }
  }
  cout << count << endl;
}