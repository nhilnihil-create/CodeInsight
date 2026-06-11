#include<bits/stdc++.h>
using namespace std;
int64_t lcm(int64_t x,int64_t y){
  if (x>y) swap(x,y);
  int64_t b=y;
  int64_t a=x;
  int64_t r=b%a;
  while(r>0){
    b=a;
    a=r;
    r=b%a;
  }
  return x*y/a;
}
int main(){
  int64_t n,m,i,p,c,l;
  cin>>n>>m;
  vector<int64_t> a(n);
  for(i=0;i<n;i++) {
    cin>>a.at(i);
    if(i==0) l=a.at(i)/2;
    c=0;
    while(a.at(i)%2==0){
      a.at(i)/=2;
      c++;
    }
    if(i==0) p=c;
    else{
      if(c!=p) break;
      l=lcm(l,a.at(i));
      if(l>m) break;
    }
  }
  if (i<n) cout<<0<<endl;
  else cout<<(m+l)/(2*l)<<endl;
}