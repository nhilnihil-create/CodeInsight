#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,k,i,l,a,s=0,c=0,ll,rr,mm;
  cin>>n>>k;
  map<int64_t,vector<int64_t>> m;
  m[0].push_back(0);
  for(i=0;i<n;i++){
    cin>>a;
    s=(s+a-1)%k;
    if(m.count(s)) m.at(s).push_back(i+1);
    else m[s].push_back(i+1);
  }
  for(auto mp:m){
    auto v=mp.second;
    l=v.size();
    if(l>=2){
      for(i=0;i<l;i++){
        ll=i;rr=l;
        while(rr-ll>1){
          mm=(ll+rr)/2;
          if(v.at(mm)-v.at(i)<k) ll=mm;
          else rr=mm;
        }
        if(ll==l-1){
          c+=(l-i)*(l-i-1)/2;
          break;
        }
        else c+=ll-i;
      }
    }
  }
  cout<<c<<endl;
}