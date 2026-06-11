#include <bits/stdc++.h>
using namespace std;

int main(){
  size_t x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  vector<int> p(a),q(b),r(c);
  multiset<int> ps,qs;
  multiset<int,greater<int>> rs;
  for(size_t i=0; i<a; i++) {
    cin>>p[i];
    if(ps.size()<x) ps.insert(p[i]);
    else if(*ps.begin()<p[i]) {
      ps.erase(ps.begin());
      ps.insert(p[i]); 
    }    
  }
  for(size_t i=0; i<b; i++) {
    cin>>q[i];
    if(qs.size()<y) qs.insert(q[i]);
    else if(*qs.begin()<q[i]) {
      qs.erase(qs.begin());
      qs.insert(q[i]); 
    }    
  }
  for(size_t i=0; i<c; i++) {
    cin>>r[i];
    rs.insert(r[i]);
  }
  for(auto ite=rs.begin(); ite!=rs.end(); ite++) {
    if(min({*ps.begin(),*qs.begin(),*ite})==*ps.begin()) {
      ps.erase(ps.begin());
      ps.insert(*ite);
    } else if(min({*ps.begin(),*qs.begin(),*ite})==*qs.begin()) {
      qs.erase(qs.begin());
      qs.insert(*ite);    
    }
  }
  cout << accumulate(ps.begin(),ps.end(),0LL)+ accumulate(qs.begin(),qs.end(),0LL) << endl;
  return 0;  
}