#include<bits/stdc++.h>
using namespace std;
void solve(){
  string s,t,r;
  cin>>s;
  cin>>t;
  int ls,lt,k=1e3+1;
  ls=s.size();
  lt=t.size();
  for(int i=0;i<ls-lt+1;i++){
    r=s.substr(i,lt);
    int p=0;
    for (int j=0;j<lt;j++){
      if (r[j]!=t[j]){
        p+=1;
      }
    }
    k=min(p,k);
  }
  cout<<k<<endl;
}
int main(){
  solve();
  return 0;
}