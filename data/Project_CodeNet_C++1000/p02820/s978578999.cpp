#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,r,s,p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  int ans=0;
  for(int i=0;i<n;i++){
    if(i<k){
      if(t[i]=='r') ans+=p;
      else if(t[i]=='s') ans+=r;
      else ans+=s;
    }
    else{
      if(t[i]!=t[i-k]){
        if(t[i]=='r') ans+=p;
        else if(t[i]=='s') ans+=r;
        else ans+=s;
      }
      else if(i<n-k){
        if(t[i]==t[i+k]) t[i]='c';
      }
    }
  }
  cout << ans << endl;
}