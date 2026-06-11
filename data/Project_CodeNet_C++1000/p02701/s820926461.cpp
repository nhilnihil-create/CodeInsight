#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> a;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.push_back(s);
    //cin >> a[i]はだめ.
  }
  sort(a.begin(), a.end());
  int ans = n;
  for(int i = 0; i < n - 1; i++) {
    if(a[i] == a[i + 1]) ans--;
  }
  cout << ans << endl;
}
