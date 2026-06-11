#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> p(n),c(n);
  for(int i=0;i<n;i++) cin>>p[i];
  for(int i=0;i<n;i++) cin>>c[i];
  for(int i=0;i<n;i++) p[i]--;
  long long ans=-1e18;
  for(int si;si<n;si++){
    int x=si;
    vector<int> s;
    long long tot=0;
    while(1){
      x=p[x];
      s.push_back(c[x]);
      tot+=c[x];
      if(x==si) break;
    }
   int l=s.size();
   long long t=0;
    for(int i=0;i<l;i++){
      t+=s[i];
      if(i+1>k) break;
      long long now=t;
      if(tot>0){
        long long e=(k-(i+1))/l;
        now+=tot*e;
      }
      ans=max(ans,now);
    }
  }
  cout<<ans<<endl;
  return 0;
}
