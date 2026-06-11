#include <bits/stdc++.h>
using namespace std;

void solve(){
  string a,b;
  int count=0;
  cin>>a>>b;
  for(int i=0;i<a.length();i++){
    if(a[i]!=b[i]) count++;
  }
  cout<<count<<'\n';
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  solve();
}
