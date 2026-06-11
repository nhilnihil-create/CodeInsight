#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  char c[n];
  int i,l=0,r=0;
  for(i=0;i<n;i++){
    cin >> c[i];
    if(c[i]=='R'){
      l++;
    }else{
      r++;
    }
  }
  int ans=0;
  for(i=0;i<l;i++){
    if(c[i]=='W'){
      ans++;
    }
  }
  for(i=l;i<n;i++){
    if(c[i]=='R'){
      ans++;
    }
  }
  ans=(ans+1)/2;
  cout << ans;
}
  
  
