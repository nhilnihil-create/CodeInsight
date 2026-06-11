#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll m;
  cin>>m;
  
  vector<ll> D(m),C(m);
  rep(i,m) cin>>D[i]>>C[i];
  
  ll sum1=0,sum2=0;
  rep(i,m) sum1+=C[i];
  rep(i,m) sum2+=C[i]*D[i];
  
  cout<<sum1-1+(sum2-1)/9<<endl;

  return 0;
}