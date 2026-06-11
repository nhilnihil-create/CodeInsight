#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  string s,t,ans="";
  cin >> n;
  cin >> s >> t;
  for(int i=0;i<n;i++){
    ans+=s.at(i);
    ans+=t.at(i);
  }
  cout << ans << endl;
  return 0;
}
