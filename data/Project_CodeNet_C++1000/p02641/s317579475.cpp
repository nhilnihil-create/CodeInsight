#include<bits/stdc++.h>
using namespace std;

set<int> dcare;

int solve(){
  int n,target,up,down,temp;
  cin>>target>>n;
  for(int i=0;i<n;i++){
    cin>>temp;
    dcare.insert(temp);
  }
  up=target;down=target;
  if(dcare.count(target)==0) return(target);
  while(1){
    up++;down--;
    if(dcare.count(down)==0) return(down);
    if(dcare.count(up)==0) return(up);
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--) cout<<solve()<<'\n';
}