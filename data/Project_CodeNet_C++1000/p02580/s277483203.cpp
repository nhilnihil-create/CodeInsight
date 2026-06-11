#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int h,w,m;
  cin>>h>>w>>m;
  map<int,int>x,y;
  set<P>se;
  rep(i,m){
    int h,w; cin>>h>>w;
    y[h]++; x[w]++;
    se.insert(P(h,w));
  }
  int mxx=0,mxy=0;
  for(auto&p:x)mxx=max(mxx,p.second);
  for(auto&p:y)mxy=max(mxy,p.second);
  vector<int>vx,vy;
  for(auto&p:x)if(p.second==mxx)vx.push_back(p.first);
  for(auto&p:y)if(p.second==mxy)vy.push_back(p.first);
  rep(i,vy.size())rep(j,vx.size()){
    if(se.find(P(vy[i],vx[j]))==se.end()){
      cout<<mxx+mxy<<endl;
      return 0;
    }
  }
  cout<<mxx+mxy-1<<endl;
}