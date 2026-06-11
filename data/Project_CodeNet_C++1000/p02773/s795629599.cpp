#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  map<string,int> mp;
  rep(i,n){
    string s;cin>>s;
    mp[s]++;
  }
  int cnt=0;
  for(auto p:mp)cnt=max(cnt,p.second);
  for(auto p:mp){
    if(cnt==p.second)cout<<p.first<<endl;
  }
}