#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  string s; cin>>s;
  int n=s.size();
  string ans="Yes";
  rep(i,n){
    if(i%2==1){
      if(s.at(i)=='R'){ans="No"; break;}
    }
    if(i%2==0){
      if(s.at(i)=='L'){ans="No"; break;}
    }
  }
  cout<<ans;
}
      

