#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  string str;
  cin>>str;
  ll ans=0;;
  vector<ll> rightsearch((ll)str.size()+1);
  vector<ll> leftsearch((ll)str.size()+1);
  rightsearch.at((ll)str.size())=0;
  for(ll i=0;i<(ll)str.size();i++){//右側の>探索
    if(str.at((ll)str.size()-1-i)=='>'){rightsearch.at((ll)str.size()-1-i)=rightsearch.at((ll)str.size()-i)+1;}
  }
  leftsearch.at(0)=0;
  for(ll i=1;i<=(ll)str.size();i++){//左側の<探索
    if(str.at(i-1)=='<'){leftsearch.at(i)=leftsearch.at(i-1)+1;}
  }
  for(ll i=0;i<=(ll)str.size();i++){
    ans+=max(rightsearch.at(i),leftsearch.at(i));
  }
  cout<<ans<<endl;
}