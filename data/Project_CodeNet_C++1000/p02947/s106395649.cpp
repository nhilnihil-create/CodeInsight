#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;

  map<string, int> mp;
  long long ans = 0;
  for(int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ans += mp[s];
    mp[s]++;
  }
  cout << ans << endl;

  return 0;
}
