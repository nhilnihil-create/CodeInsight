#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,n;
  cin>>h>>w>>n;
  vector<int> hs(h),ws(w);
  set<pair<int,int>> s;
  for(int i=0;i<n;i++){
     int r,c;
     cin>>r>>c;
     --r;--c;
    hs[r]++;
    ws[c]++;
    s.emplace(r,c);
  }
  int mh=0,mw=0;
  for(int i=0;i<h;i++) mh=max(mh,hs[i]);
  for(int j=0;j<w;j++) mw=max(mw,ws[j]);
  vector<int> is,js;
  for(int i=0;i<h;i++) if(mh==hs[i]) is.push_back(i);
  for(int i=0;i<w;i++) if(mw==ws[i]) js.push_back(i);
  int ans=mh+mw;
  for(int i:is) for(int j:js){
    if(s.count(pair(i,j))) continue;
    cout<<ans<<endl;
    return 0;
  }
  --ans;
  cout<<ans<<endl;
  return 0;
}
