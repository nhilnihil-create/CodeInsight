#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s, t;
  cin >> s >> t;
  int mn = INT_MAX;
  for(int i = 0; i <= s.size() - t.size(); i++){
    int cur = 0;
    for(int j = 0; j < t.size(); j++){
      if(s[i + j] != t[j]) cur++;
    }
    mn = min(mn, cur);
  }
  cout << mn << "\n";
}
