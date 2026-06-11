#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  map<string,int> s;
  int n;
  cin >>n;
  int c=1;
  rep(i,n){
    string t;
     cin >> t;
    if(s.find(t)==s.end()){
      s.insert(make_pair(t,1));
    }
    else {
      ++s.at(t);
      c= max(c,s.at(t));
    }
  }
  for(auto itr = s.begin(); itr != s.end(); ++itr){
    if(itr->second==c) cout << itr->first << endl;
  }
  return 0;
}
