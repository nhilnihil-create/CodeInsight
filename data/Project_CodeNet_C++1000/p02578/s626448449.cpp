#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  int m = 0;
  int64_t s = 0;
  for (int i = 0; i < n; i++){
    m = max(m, a.at(i));
    if (m > a.at(i)){
      s += m - a.at(i);
    }
  }
  cout << s << endl;
}