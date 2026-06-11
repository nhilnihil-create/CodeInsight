#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<ld,P> P2;
P2 mk_P(ld a,ll b,ll c){
  return P2(a,P(b,c));
}
int main(){
  ll n;
  cin>>n;
  vector<P2> vec;
  for(int i=0;i<n;i++){
    ll x,y;
    ld angle;
    cin>>x>>y;
    if(y>0){
      angle=acos((ld)x/sqrt((ld)(x*x+y*y)));
    }
    else if(y==0){
      if(x>0) angle=0;
      else if(x<0) angle=M_PI;
      else continue;
    }
    else{
      angle=acos((ld)(-1*x)/sqrt((ld)(x*x+y*y)))+M_PI;
    }
    vec.push_back(mk_P(angle,x,y));
  }
  sort(vec.begin(),vec.end());
  int as=vec.size();
  for(int i=0;i<as;i++){
    P2 p=vec[i];
    p.first+=2*M_PI;
    vec.push_back(p);
  }
  ll ans=0;
  for(int i=0;i<as;i++){
    for(int j=i;j<i+as;j++){
      ll kx=0,ky=0;
      for(int k=i;k<=j;k++){
        kx+=vec[k].second.first;
        ky+=vec[k].second.second;
      }
      ll kans=kx*kx+ky*ky;
      ans=max(ans,kans);
    }
  }
  cout<<fixed;
  cout<<setprecision(20)<<sqrt((ld)ans)<<endl;
}
