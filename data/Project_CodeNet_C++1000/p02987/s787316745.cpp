#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  map<char,int> mp;
  rep(i,4){
    char s; cin >> s;
    auto itr = mp.find(s);        // "s" が設定されているか？
    if( itr != mp.end() )
      mp[s]++;
    else
      mp[s] = 1;
  }
  
  bool ok = true;
  for(auto it = mp.begin(); it!=mp.end(); it++){
    if(it->second != 2)
      ok = false;
    //cout << it->second << endl;
  }
  if(mp.size() != 2)
    ok = false;
  //cout << mp.size() << endl;
  
  if(ok)  cout << "Yes" << endl;
  else  cout << "No" << endl;
}