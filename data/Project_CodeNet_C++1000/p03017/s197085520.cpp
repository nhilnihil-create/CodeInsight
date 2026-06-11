#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,a,b,c,d,i;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  s="#"+s+"#";
  bool ni=true;
  bool san=false;
  if(d>c){
    for(i=a;i<=c-1;++i){
      if(s[i]=='#' && s[i+1]=='#'){
        ni=false;
      }
    }
    for(i=b;i<=d-1;++i){
      if(s[i]=='#' && s[i+1]=='#'){
        ni=false;
      }
    }
    if(ni==true){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    for(i=a;i<=c-1;++i){
      if(s[i]=='#' && s[i+1]=='#'){
        ni=false;
      }
    }
    for(i=b;i<=d-1;++i){
      if(s[i]=='#' && s[i+1]=='#'){
        ni=false;
      }
    }
    for(i=b;i<=d;++i){
      if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.'){
        san=true;
      }
    }
    if(ni==true && san==true){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
