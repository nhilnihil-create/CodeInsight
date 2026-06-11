#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
int n,ans=0;
  cin>>n;
  vector<int> h(n);
  REP(i,n){cin>>h[i];}
  int t=0;
  REP(i,n-1){
  if(h[i]>=h[i+1])t++;
    else t=0;
    ans=max(t,ans);
  }
  cout<<ans<<endl;
}