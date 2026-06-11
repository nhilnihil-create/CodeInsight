#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  string x;
  for(int i = 0; i < n; i++) { cin >> s.at(i) >> t.at(i); } 
  cin >> x;
  
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(s.at(i) == x) {
      i++;
      for(int j = i; j < n; j++) {
        ans = ans + t.at(j);
      }
      cout << ans << endl;
      return 0;
    }
  }
}
  