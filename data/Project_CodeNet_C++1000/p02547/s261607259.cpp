#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  int ans = 0,o = 0;
  while(t--){
    int a,b;
    cin >> a >> b;
    if(a==b) o++;
    else o=0;
    ans=max(ans,o);
  }
  if(ans>=3) cout <<"Yes";
  else cout <<"No";
  return 0;
}