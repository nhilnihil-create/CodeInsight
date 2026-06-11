#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n;
ll m;
vector<ll> a;
vector<ll> sum;
vector<ll> rle;
vector<ll> v;
bool C(ll x,ll y){
  // cout << y <<":"<<rle[x] << "\n";
  return y<rle[x];
}
ll upper(ll l,ll r,ll y){
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C(mid,y)) ub=mid;
    else lb=mid;
  }
  return ub;
}
bool C2(ll y,ll k){
  ll j=upper(0,m-1,y);
  // cout << y <<":"<<j << "\n";
  return sum[m]-sum[j]-(m-j)*y<=n-y*k;
}

ll lower(ll l,ll r,ll k){
  
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C2(mid,k)) lb=mid;
    else ub=mid;
  }
  return lb;
}

int main()
{
  cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());


  ll cnt=1;
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      rle.push_back(cnt);
      cnt=1;
    }
  }
  rle.push_back(cnt);

  sort(rle.begin(), rle.end());
  
  
  m=rle.size();
  
  
  sum.resize(m+1);
  sum[0]=0;
  rep(i,m){
    sum[i+1] = sum[i]+rle[i];
  }


  rep1(k,n){
    cout << lower(1,n/k,k) << "\n";
  }
  return 0;
}
