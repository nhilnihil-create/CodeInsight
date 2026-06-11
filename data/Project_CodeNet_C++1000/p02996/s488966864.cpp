#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  map<int,int> mp;
  rep(i,n){
    int a,b; cin>>a>>b;
    mp[b]+=a;
  }
  int time=0;
  bool ans=1;
  for(auto x : mp){
    time+=x.second;
    if(time>x.first) ans=0;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}


