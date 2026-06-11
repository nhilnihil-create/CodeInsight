#include<bits/stdc++.h>
using namespace std;
int main(void){
  int mh=0,mw=0,h,w,m; cin>>h>>w>>m;
  vector<int> ch(m),cw(m),bh(h,0),bw(w,0);
  for(int i=0; i<m; ++i){
    cin>>ch[i]>>cw[i]; --ch[i]; --cw[i];
    mh=max(mh,++bh[ch[i]]);
    mw=max(mw,++bw[cw[i]]);
  }
  set<int> a,b;
  for(int i=0; i<m; ++i){
    if(bh[ch[i]]==mh) a.insert(ch[i]);
    if(bw[cw[i]]==mw) b.insert(cw[i]);
  }
  int cnt=0;
  for(int i=0; i<m; ++i){
    if(bh[ch[i]]==mh&&bw[cw[i]]==mw) ++cnt;
    if(cnt==(a.size()*b.size())){ cout<<mh+mw-1; return 0;}
  }
  cout<<mh+mw;
  return 0;
}