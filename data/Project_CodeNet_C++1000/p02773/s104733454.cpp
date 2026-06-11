#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;
  map<string,int>mp;
  rep(i,n){
    string s; cin>>s;
    mp[s]++;
  }
  int mx=0;
  for(auto&p:mp){
    mx=max(mx,p.second);
  }
  for(auto&p:mp){
    if(p.second==mx)cout<<p.first<<endl;
  }
}