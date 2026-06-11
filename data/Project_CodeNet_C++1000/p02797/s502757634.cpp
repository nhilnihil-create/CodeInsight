#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(long long)(n);i++)
#define love emplace_back
using vi=vector<int>;
template<class T> void I_love(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k,s;
  cin>>n>>k>>s;
  vi MIIHI;
  rep(i,k) MIIHI.love(s);
  if(s==1000000000) rep(i,n-k) MIIHI.love(1);
  else rep(i,n-k) MIIHI.love(s+1);
  I_love(MIIHI);
}
