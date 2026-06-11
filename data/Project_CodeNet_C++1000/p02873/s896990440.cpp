#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.size();
  vector<int> smaller;
  int num = 0;
  smaller.push_back(num);
  rep(i, len) {
    if(s[i]=='<') ++num;
    else num = 0;
    smaller.push_back(num);
  }
  
  vector<int> bigger;
  num = 0;
  bigger.push_back(num);
  rep(i, len) {
    if(s[len-i-1]=='>') ++num;
    else num = 0;
    bigger.push_back(num);
  }
  
  reverse(all(bigger));
  
  ll ans = 0;
  rep(i,len+1) {
    ans += max(smaller[i], bigger[i]);
//    cout << smaller[i] << " " << bigger[i] << endl;
  }
  
//  cout << smaller.size() << " " << bigger.size() << endl;
  
  cout << ans << endl;
  
  return 0;
}
