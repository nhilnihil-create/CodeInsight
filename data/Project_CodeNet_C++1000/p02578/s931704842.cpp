#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> v(n);
  
  for (int i = 0; i < n; i++)
    cin >> v.at(i);
  
  long long h = 0;
  
  for (int i = 0; i < n - 1; i++) {
    if (v.at(i) > v.at(i + 1)) {
      h += v.at(i) - v.at(i + 1);
      v.at(i + 1) = v.at(i);
    }
  }
  
  cout << h << endl;
  
}
      