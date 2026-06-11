#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

int main() {

  int n;
  cin >> n;
  vector<string> S;
  S.reserve(n);

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    S.push_back(s);
  }

  sort(S.begin(), S.end());

  S.push_back("OMAEHADAREDA");

  LL ans = 0, cnt = 1;

  for(int i = 0; i < n; ++i){
    if(S.at(i) == S.at(i+1)) cnt++;
    else {
      ans += cnt*(cnt-1)/2;
      cnt = 1;
    }
  }
  cout << ans << endl;

  return 0;
}
