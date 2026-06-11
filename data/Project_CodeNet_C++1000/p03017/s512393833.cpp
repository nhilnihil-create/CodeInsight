#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  a--;
  b--;
  c--;
  d--;
  string s; 
  cin >> s;
  bool ex=true;
  if(c<d){
    rep2(i,a+1,c-1){
      if(s.at(i)=='#'&&s.at(i+1)=='#'){
        ex=false;
      }
    }
    rep2(i,b+1,d-1){
      if(s.at(i)=='#'&&s.at(i+1)=='#'){
        ex=false;
      }
    }
  }
  else{
    rep2(i,a+1,c-1){
      if(s.at(i)=='#'&&s.at(i+1)=='#'){
        ex=false;
      }
    }
    rep2(i,b+1,d-1){
      if(s.at(i)=='#'&&s.at(i+1)=='#'){
        ex=false;
      }
    }
    if(ex){
      ex=false;
      rep2(i,b-1,d){
        if(s.at(i)=='.'&&s.at(i+1)=='.'&&s.at(i+2)=='.'){
          ex=true;
        }
      }
    }
  }
  if(ex){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}