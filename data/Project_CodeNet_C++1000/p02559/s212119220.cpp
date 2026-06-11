#include<bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int64_t op(int64_t a,int64_t b){
  return a+b;
}
int64_t e(){
  return 0;
}
int main(){
  int n,q;
  cin>>n>>q;
  vector<int64_t> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  segtree<int64_t,op,e> t(a);
  for(int _=0;_<q;_++){
    int f,x,y;
    cin>>f>>x>>y;
    if(f==0)
      t.set(x,t.get(x)+y);
    if(f==1)
      cout<<t.prod(x,y)<<endl;
  }
}