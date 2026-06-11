#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  string ans = "No";
  for (int i = 2; i <= 10; i += 2) {
    if (s == string("hihihihihi", i)) {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}
