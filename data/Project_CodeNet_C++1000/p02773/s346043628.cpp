#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  map<string,int> mp;
  int cnt=0;
  rep(i,n){
    string s;cin>>s;
    mp[s]++;
    cnt=max(cnt,mp[s]);
  }
  for(auto x:mp){
    if(cnt==x.second)cout<<x.first<<endl;
  }
}