#include<bits/stdc++.h>
using namespace std;
int main(void){
  int x,n;cin>>x>>n;
  vector<int> p(n);
  for(int i=0; i<n; ++i) cin>>p[i];
  vector<bool> q(102,true);
  for(int i=0; i<n; ++i) q[p[i]]=false;
  vector<int> r;
  for(int i=0; i<102; ++i) if(q[i]==true) r.push_back(i);
  auto s=lower_bound(r.begin(),r.end(),x);
  auto t=upper_bound(r.begin(),r.end(),x);
  if(s<t) cout<<*s<<endl;
  else if(*t-x<x-*(t-1)) cout<<*t<<endl; else cout<<*(t-1)<<endl;
  return 0;
}
