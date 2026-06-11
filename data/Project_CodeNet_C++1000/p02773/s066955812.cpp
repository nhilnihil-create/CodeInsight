#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  map<string,int> mp;
  
  rep(i, n){
    string s; cin >> s;
    auto itr = mp.find(s);
    if(itr != mp.end())
      mp[s]++;
    else
      mp[s] = 1;
  }
  int max = 0;
  for(auto it = mp.begin(); it != mp.end(); it++)
    if(max < it->second)  max = it->second;
  
  for(auto it = mp.begin(); it != mp.end(); it++){
    if(max == it->second)  cout << it->first << endl;
  }
}