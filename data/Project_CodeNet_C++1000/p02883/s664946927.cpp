#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

ll n;
ll A[1000010],F[1000010];

ll f(ll x){
  ll sum=0;
  rep(i,n){
    if(A[i]*F[i]>x){ 
      sum+=A[i]-x/F[i];
    }
  }
  return sum;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll k;
  cin>>n>>k;

  rep(i,n) cin>>A[i];
  rep(i,n) cin>>F[i];
  
  sort(A,A+n);
  sort(F,F+n,greater<int>());
  
  ll l=-1,r=1e12+7;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(f(mid)>k) l=mid;
    else r=mid;
  }
  cout<<r<<endl;
  
  return 0;
}