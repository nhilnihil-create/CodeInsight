#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t,k = "";int i,ans = 0;cin >> s;
  t = s.substr(0,1);
  for(i=1;i<s.size();i++){
    k += s.substr(i,1);
    if(k!="" && t!=k){
      ans++;t = k;k = "";
    }
  }
  cout << ans+1 << "\n";
}