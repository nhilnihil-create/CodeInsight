#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, ma =  0;
  cin >> N;
  string s;
  unordered_map<string, int> mp;
  vector<string> ans;
  for(ll i = 0; i < N; i++) {
    cin >> s;
    mp[s]++;
    if(mp[s] >= ma) ma = mp[s];
  }
  for(auto& p : mp) {    
    if(p.second == ma) ans.push_back(p.first);
  }
  sort(ans.begin(), ans.end());
  for(ll i = 0; i < ans.size(); i++) cout << ans.at(i) << endl;
}