#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
  int n, t[100010];
  string s[100010], x;
  int ans = 0, sub;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
  }
  
  cin >> x;

  for (int i = 0; i < n; i++) {
      if (s[i] == x) {
          sub = i;
          break;
      }
  }

  for (int i = sub+1; i < n; i++) {
      ans += t[i];
  }

  cout << ans << endl;
  
}
