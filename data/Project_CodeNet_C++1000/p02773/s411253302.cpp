#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  map<string,int> s;
  int n;
  cin >>n;
  vector<string> t(n);
  rep(i,n) cin >> t[i];
  int c=1;
  rep(i,n){
    if(s.find(t[i])==s.end()){
      s.insert(make_pair(t[i],1));
    }
    else {
      ++s.at(t[i]);
      c= max(c,s.at(t[i]));
    }
  }
  for(auto itr = s.begin(); itr != s.end(); ++itr){
    if(itr->second==c) cout << itr->first << endl;
  }
  return 0;
}
