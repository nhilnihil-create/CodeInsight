#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  ll n;
  cin>>n;
  ll ans=0;
  ll co=n/10;
  while(co>0){
    ans+=co;
    co/=5;
  }
  if(n%2==0){
    cout<<ans<<endl;  
  }
  else{
    cout<<0<<endl;
  }
}

