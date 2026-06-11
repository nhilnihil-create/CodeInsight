#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end(), less<ll>());
  
  vector<ll> l;
  vector<ll> r;

  l.push_back(a[0]);
  r.push_back(a[n-1]);

  rep(i,n-2){
    if(a[i+1]>0){
      r.push_back(a[i+1]);
    }else{
      l.push_back(a[i+1]);
    }
  }
  vector<P> ans;
  ll x = l[l.size()-1];
  ll y;
  rep(i,r.size()-1){
    y = r[i];
    P p = {x,y};
    ans.push_back(p);
    x = x-y;
  }

  y = x;
  x = r[r.size()-1];
  P p = {x,y};
  ans.push_back(p);
  x = x-y;

  rep(i,l.size()-1){
    y = l[i];
    P p = {x,y};
    ans.push_back(p);
    x = x-y;
  }

  cout << x << endl;
  rep(i,n-1){
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
} 