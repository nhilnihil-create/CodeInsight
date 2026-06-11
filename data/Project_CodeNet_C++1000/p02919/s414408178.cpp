#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> o(n);
  for(int i=1;i<=n;i++){
    int p;
    cin>>p;
    o.at(p-1)=i;
  }
  set<int> s;
  s.insert(0);
  s.insert(n+1);
  int64_t a=0;
  for(int i=n-1;i>=0;i--){
    auto l=prev(s.lower_bound(o.at(i)));
    auto r=s.lower_bound(o.at(i));
    int64_t xl=(*l==0?0:(int64_t)(*l-*prev(l))*(*r-o.at(i)));
    int64_t xr=(*r==n+1?0:(int64_t)(o.at(i)-*l)*(*next(r)-*r));
    a+=(xl+xr)*(i+1);
    s.insert(o.at(i));
  }
  cout<<a<<endl;
}