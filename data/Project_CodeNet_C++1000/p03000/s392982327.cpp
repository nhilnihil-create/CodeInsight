#include <bits/stdc++.h> 
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> li(n);
  for (int i = 0; i < n; i++) cin >> li.at(i);
  
  int ans = 1;
  int d = 0;
  for (int l : li) {
    d += l;
    if (d > x) break;
    ans++;
  }
  cout << ans << endl;
}