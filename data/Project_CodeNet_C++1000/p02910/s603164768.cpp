#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
 
int main(void) {
  string s;cin>>s;
  bool can = true;
  fr(i, s.size()){
    if(i%2){
      if(s[i]=='R') can = false;
    }else{
      if(s[i]=='L') can = false;
    }
  }

  cout << (can? "Yes":"No")<< endl;

  return 0;
}