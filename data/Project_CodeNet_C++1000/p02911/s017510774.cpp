#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
int n,k,q,ans=0;
  cin>>n>>k>>q;
  vector<int> p(n,0);
  REP(i,q){
    int a;
    cin>>a;
    p[a-1]++;
  }
  REP(i,n){
  if(p[i]>-k+q)cout<<"Yes\n";
    else cout<<"No\n";
  }

  return 0;
}