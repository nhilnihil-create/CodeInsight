#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int n=t.size();
  int m=s.size();
  int ans=10000;
  for(int i=0;i<m-n+1;i++){
    int cnt=0;
    for(int j=0;j<n;j++){
      if(s.at(i+j)==t.at(j)) cnt++;
    }
    ans=min(ans,n-cnt);
  }
  cout << ans << endl;
  return 0;
}