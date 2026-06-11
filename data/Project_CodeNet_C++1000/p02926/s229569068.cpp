#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 200003
#define MOD 1000000007

int main(){
  int N;
  cin>>N;
  vector<pair<double,pair<ll,ll>>> xy(N);
  for(int i=0;i<N;i++){
    ll x,y;
    cin>>x>>y;
    xy.at(i).second.first=x;
    xy.at(i).second.second=y;
    complex<double> c(x,y);
    xy.at(i).first=arg(c);
  }
  

  sort(xy.begin(),xy.end());

  ll ans=0;
  for(int i=0;i<N;i++){
    ll x=0;
    ll y=0;
    for(int j=0;j<N;j++){
      x+=xy.at((i+j)%N).second.first;
      y+=xy.at((i+j)%N).second.second;
      ans=max<ll>(ans,x*x+y*y);
    }
  }
  printf("%.12Lf\n",sqrtl(ans));
}
