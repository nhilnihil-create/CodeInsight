#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s;
  cin>>s;
  int tmp=1;
  vector<P> p;
  int right = 0, left = 0; 
  rep(i,s.size()-1){
    if(s[i] == 'R') right++;
    if(s[i] == 'L') left++;
    if(s[i]=='L' && s[i+1]=='R'){
      p.push_back(make_pair(right,left));
      right = 0; left = 0;
    }
  }
  p.push_back(make_pair(right,left+1));
  vector<int> ans;
  for(auto x : p){
    rep(i,x.first+x.second){
      if(i == x.first-1) ans.push_back((x.first + 1) / 2 + x.second /2);
      else if(i == x.first) ans.push_back((x.second + 1) / 2 + x.first /2);
      else ans.push_back(0);
    }
  }
  for(auto a : ans){
    cout<<a<<" ";
  }
  cout<<endl;
}