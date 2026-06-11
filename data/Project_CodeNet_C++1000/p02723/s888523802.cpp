#include <bits/stdc++.h>
using namespace std;
 
 
void solve(){
  string main;
  cin>>main;
  if(main[3]==main[2] && main[5]==main[4]) cout<<"Yes"<<'\n';
  else cout<<"No"<<"\n";
  return;
}



int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--) solve();
}
