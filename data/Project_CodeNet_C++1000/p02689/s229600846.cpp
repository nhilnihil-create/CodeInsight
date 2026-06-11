#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int n,m;
  cin>>n>>m;
 vector<int>h(n,0);
 vector<bool>ok(n,true);
   rep(i,n) cin>>h.at(i);
   rep(i,m){
  	int a,b;
    cin>>a>>b;
  	a--; b--;
     if (h.at(a) <= h.at(b)) ok.at(a) = false;
    if (h.at(b) <= h.at(a)) ok.at(b) = false;
  }
  int ans=0;
  rep(i,n){
  	if(ok.at(i)) ans++;
  }
  cout<<ans<<endl;
}
// 片方を比べてどちらかがアウトになるので、そうなったやつは消す