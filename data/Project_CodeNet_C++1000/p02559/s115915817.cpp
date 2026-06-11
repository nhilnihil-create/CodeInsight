#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
  int n,q;
  cin>>n>>q;
  fenwick_tree<int64_t> t(n);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    t.add(i,a);
  }
  for(int _=0;_<q;_++){
    int f,x,y;
    cin>>f>>x>>y;
    if(f==0)
      t.add(x,y);
    if(f==1)
      cout<<t.sum(x,y)<<endl;
  }
}