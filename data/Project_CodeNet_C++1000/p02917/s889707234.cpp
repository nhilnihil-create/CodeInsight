#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
int n,ans=0;
  cin>>n;
  vector<int> b(n);
  REP(i,n){cin>>b[i];}
  ans+=(b[0]+b[n-2]);
  REP(i,n-1){
  ans+=min(b[i],b[i+1]);
  }
  cout<<ans<<endl;
  return 0;
}