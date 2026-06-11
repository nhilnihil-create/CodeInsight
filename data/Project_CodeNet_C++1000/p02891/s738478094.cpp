#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  string s;
  cin >>s;
  int k;
  cin>>k;
  bool ex=true;
  rep(i,s.size()-1){
    if(s.at(i)!=s.at(i+1)){
      ex=false;
      break;
    }
  }
  if(ex){
    cout<<s.size()*k/2<<endl;
  }
  else{
  string t=s+s;
  string u=t+s;
  long ans=0;
  if(k==1){
    rep(i,s.size()-1){
      if(s.at(i)==s.at(i+1)){
        ans++;
        s.at(i+1)='.';
      }
    }
  }
  else if(k==2){
    rep(i,t.size()-1){
      if(t.at(i)==t.at(i+1)){
        ans++;
        t.at(i+1)='.';
      }
    }
  }
  else{
    long ch=0;
    rep(i,u.size()-1){
      if(u.at(i)==u.at(i+1)){
        ch++;
        u.at(i+1)='.';
      }
    }
    long co=0;
    rep(i,t.size()-1){
      if(t.at(i)==t.at(i+1)){
        co++;
        t.at(i+1)='.';
      }
    }
    ans=co+(k-2)*(ch-co);
  }
  cout<<ans<<endl; 
  }
}