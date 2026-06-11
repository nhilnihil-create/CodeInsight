#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w,m,b,bb;
  cin >> h >> w >> m;
  map<pair<int,int>,bool>a;
  map<int,int>tate;
  map<int,int>yoko;
  for(int i=0;i<m;i++){
    cin >> b >> bb;
    a[make_pair(b-1,bb-1)]=true;
    tate[b-1]++;
    yoko[bb-1]++;
  }
  b=0,bb=0;
  set<int>mh;
  set<int>mw;
  for(auto x:tate)
    b=max(b,x.second);
  for(auto x:tate)
    if(x.second==b)
      mh.insert(x.first);
  for(auto x:yoko)
    bb=max(bb,x.second);
  for(auto x:yoko)
    if(x.second==bb)
      mw.insert(x.first);
  bool ok=false;
  for(auto x:mh){
    for(auto y:mw){
      if(!a[make_pair(x,y)]){
        ok=true;
        break;
      }
    }
    if(ok)
      break;
  }
  cout << b+bb-(ok?0:1) << endl;
  return 0;
}