#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
  string s;
  cin>>s;
  string t,h="";
  int ans=0;
  for(int i=0;i<s.size();i++){
   t+=s[i];
   if(t==h){continue;}
   h=t;
   t="";
   ans++;
  }
  cout<<ans<<endl;
   return 0;
  }