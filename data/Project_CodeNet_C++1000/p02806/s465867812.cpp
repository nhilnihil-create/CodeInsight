#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<pair<string, int>> playlist(n);
  for (int i = 0; i < n; i++) {
    string s;
    int t;
    cin >> s >> t;
    playlist.at(i).first = s;
    playlist.at(i).second = t;
  }

  string playing;
  cin >> playing;
  bool flag = false;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (playlist.at(i).first == playing) {
      flag = true;
      continue;
    }
    if (flag == true) ans += playlist.at(i).second;
  }
  cout << ans << endl;
  return 0;
}