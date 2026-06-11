#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

bool isOK(int index,int ch,vector<int> &vec){
  return (vec[index] >= ch); 
}

void nibutan(int ch ,vector<int> &vec){
  int ok=-1, ng=vec.size();
  while(ng-ok>1){
    int middle = (ok+ng)/2;
    if(isOK(middle,ch,vec)) ok=middle;
    else ng=middle;
  }
  vec.insert(vec.begin()+ng,ch);
  vec.pop_back();
  return;
}

int main(){
  int x,y,a,b,c;
  cin>>x>>y>>a>>b>>c;
  vector<int> p(a),q(b),r(c);
  rep(i,a) cin>>p[i];
  rep(i,b) cin>>q[i];
  rep(i,c) cin>>r[i];
  sort(p.begin(),p.end(),greater<int>());
  sort(q.begin(),q.end(),greater<int>());
  sort(r.begin(),r.end(),greater<int>());
  p.erase(p.begin()+x,p.end());
  q.erase(q.begin()+y,q.end());
  for(auto d : r){
    if(d<=p[x-1] && d<=q[y-1]) break;
    if(p[x-1]<q[y-1]) nibutan(d,p);
    else nibutan(d,q);
  }
  ll ans=0;
  rep(i,x) ans+=p[i];
  rep(i,y) ans+=q[i];
  cout<<ans<<endl;
}

