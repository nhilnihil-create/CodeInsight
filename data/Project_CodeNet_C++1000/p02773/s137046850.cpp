#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  map<string, int>mp;
  for (int i=0; i<n; i++){
    string s; cin >> s;
    mp[s]++;
  }
  int mx = 0;
  for (auto p : mp) mx = max(p.second, mx);
  for (auto p : mp){
    if (p.second == mx) cout << p.first << endl;
  }
}