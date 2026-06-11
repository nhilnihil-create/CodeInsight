#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n,m;
  cin >> n >> m;
  vector<int> s(m),c(m);
  for(int i=0;i<m;i++)cin >> s[i] >> c[i];
  for(int i=0;i<1000;i++){
    string x = to_string(i);
    if(x.size()==n){
      bool valid = true;
      for(int j=0;j<m;j++)if(x[s[j]-1]!=('0'+c[j]))valid=false;
      if(valid){cout << i << endl; return;}
    }
  }
  cout << -1 << endl;
}
int main(){
  solve();
  return 0;
}