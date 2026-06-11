#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string s;
  cin >> s;
  vector<int> a(s.size(),0);
  int f=0;
  int g=0;
  bool ex=true;
  rep(i,s.size()-1){
    if(s.at(i)=='L'&&s.at(i+1)=='R'){
      g=i;
      ex=false;
      break;
    }
  }
  if(ex){
    g=s.size()-1;
  }
  while(g<s.size()-1){
    ex=true;
    rep2(i,f,g){
      if(s.at(i)=='R'&&s.at(i+1)=='L'){
        a.at(i)=(i-f)/2+(g-i+2)/2;
        a.at(i+1)=(i+1-f)/2+(g-i+1)/2;
      }
    }
    f=g+1;
    rep2(i,f,s.size()-1){
      if(s.at(i)=='L'&&s.at(i+1)=='R'){
        g=i;
        ex=false;
        break;
      }
    }
    if(ex){
      g=s.size()-1;
    }
  }
  rep2(i,f,g){
    if(s.at(i)=='R'&&s.at(i+1)=='L'){
      a.at(i)=(i-f)/2+(g-i+2)/2;
      a.at(i+1)=(i+1-f)/2+(g+1-i)/2;
    }
  }
  rep(i,s.size()) {
    cout<<a.at(i)<<" ";   
  }
  cout<<endl;
}