#include<bits/stdc++.h>
using namespace std;
int64_t mod=1000000007;
vector<int64_t> f(1000010),fi(1000010);
int64_t pw(int64_t a,int64_t b){
  int64_t z;
  if(b==0) return 1;
  else{
    z=pw(a,b/2)*pw(a,b/2)%mod;
    if(b%2==1) z=z*a%mod;
    return z;
  }
}
int64_t comb(int64_t a,int64_t b){
  return f.at(a)*fi.at(b)%mod*fi.at(a-b)%mod;
}
int main(){
  int64_t x,y,i;
  cin>>x>>y;
  f.at(0)=1; fi.at(0)=1;
  for(i=1;i<=max(x,y);i++){
    f.at(i)=f.at(i-1)*i%mod;
    fi.at(i)=fi.at(i-1)*pw(i,mod-2)%mod;
  }
  if(x==y){
    if(x%3>0) cout<<0<<endl;
    else cout<<comb(x/3*2,x/3)<<endl;
  }
  else{
    if(x>y) swap(x,y);
    if((x+y)%3>0) cout<<0<<endl;
    else if(2*x<y) cout<<0<<endl;
    else cout<<comb((x+y)/3,(2*x-y)/3)<<endl;
  }
}