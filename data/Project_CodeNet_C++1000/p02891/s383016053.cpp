#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s,s2;
  ll k;
  ll ans;
  cin>>s>>k;
  s2=s+s;
  bool all=1;
  rep(si,s.size()-1){
    if(s[si]!=s[si+1]) all=0; 
  }
  if(all){
    ans=(ll)s.size() * k / 2;
  }else{
    vector<int> vec_s,vec_s2;
    int tmp=1;
    rep(si,s.size()-1){
      if(s[si]==s[si+1]){
        tmp++;
      }else if(tmp!=1){
        vec_s.push_back(tmp);
        tmp=1;
      }
    }
    if(tmp!=1){
      vec_s.push_back(tmp);
    }
    tmp=1;
    rep(si,s2.size()-1){
      if(s2[si]==s2[si+1]){
        tmp++;
      }else if(tmp!=1){
        vec_s2.push_back(tmp);
        tmp=1;
      }
    }
    if(tmp!=1){
      vec_s2.push_back(tmp);
    }
    int ch1=0,ch2=0;
    for(auto x : vec_s){
      ch1+=x/2;
    }
    for(auto x : vec_s2){
      ch2+=x/2;
    }
    ans=ch1+(ch2-ch1) * (k-1);
  }
  cout<<ans<<endl;
}

