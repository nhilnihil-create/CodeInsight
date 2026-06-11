#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  string s,t;
  cin >> s>>t;
   
  vector<bool> a(26);
  vector<long> c[26];
  rep(i,s.size()) {
    a.at(s.at(i)-'a')=true;
    c[s.at(i)-'a'].push_back(i);
  }
  bool b=true;   
  rep(i,t.size()){
    if(!a.at(t.at(i)-'a')){
      b=false;
      break;
    }
  }
  if(b){
    long ans;
    vector<long> d(t.size());
    long ch=-1;
    rep(i,t.size()){     
      auto itr = upper_bound(c[t[i]-'a'].begin(), c[t[i]-'a'].end(), ch);
      if(itr==c[t[i]-'a'].end()){
        d.at(i)=c[t.at(i)-'a'].at(0);
        ch=d.at(i);
      }
      else{
        d.at(i)=*itr;
        ch=d.at(i);
      }
    }
    long co=0;
    rep(i,t.size()-1){
      if(d.at(i)>=d.at(i+1)){
        co++;
      }
    }
    ans=co*s.size()+d.at(t.size()-1)+1;
    cout<<ans<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
}