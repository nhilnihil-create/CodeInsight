#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<char> vec={a,b,c,d};
  sort(vec.begin(),vec.end());
  string ans = "No";
  if (vec[0]==vec[1] && vec[1] != vec[2] && vec[2]== vec[3]) ans = "Yes";
  cout << ans << endl;
}
