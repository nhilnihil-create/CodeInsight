#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int m, n, s;
  char c;
  cin>>n>>m;
  bool no = false;
  string ans;
  rep(i, n) ans+='a';
  rep(i, m){
    cin>>s>>c;
    if(ans.at(s-1)=='a') {
      ans.at(s-1)=c;
    }
    else{
      if(ans.at(s-1)==c){
        continue;
      }
      else{
        no=true;
        break;
      }
    }
  }
  rep(i, n){
    if(ans.at(i)=='a'){
      if(i==0 && n!=1) ans.at(i)='1';
      else ans.at(i)='0';
    }
  }
  if(ans.at(0)=='0' && n>1) no=true;
  if(no) cout<<-1<<endl;
  else cout<<ans<<endl;
}