#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<int>ans(n);
  int odd=0,even=0;
  for(int i=0;i<n;i++){
    if(s[i]=='R'){
      if(i%2==0){even++;}
      else{odd++;}
    }
    else{
      if(i%2==0){ans[i]+=even;ans[i-1]+=odd;even=0;odd=0;}
      else{ans[i]+=odd;ans[i-1]+=even;odd=0;even=0;}
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='L'){
      if(i%2==0){even++;}
      else{odd++;}
    }
    else{
      if(i%2==0){ans[i]+=even;ans[i+1]+=odd;even=0;odd=0;}
      else{ans[i]+=odd;ans[i+1]+=even;odd=0;even=0;}
    }
  }
  for(int i=0;i<n;i++){
    cout<<ans[i];
    if(i<n-1){cout<<" ";}
  }cout<<endl;
  return 0;  
}