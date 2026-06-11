#include<bits/stdc++.h>
using namespace std;
int fin(vector<int> &f,int v){
  if(f.at(v)==f.size())
    return v;
  f.at(v)=fin(f,f.at(v));
  return f.at(v);
}
void uni(vector<int> &f,vector<int> &h,int x,int y){
  if(h.at(x)>h.at(y)){
    uni(f,h,y,x);
    return;
  }
  if(x==y)
    return;
  f.at(x)=y;
  h.at(y)=max(h.at(x)+1,h.at(y));
  return;
}
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> f(n,n);
  vector<int> h(n,0);
  for(int _=0;_<q;_++){
    int t,u,v;
    cin>>t>>u>>v;
    int x=fin(f,u);
    int y=fin(f,v);
    if(t==0)
      uni(f,h,x,y);
    if(t==1)
      cout<<(x==y)<<endl;
  }
}