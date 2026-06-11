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
  int ans = 0;
  for (int i = n-1; i > 0; i--) {
      if (playlist.at(i).first == playing) break;
      ans += playlist.at(i).second;
  }
  cout << ans << endl;
  return 0;
}