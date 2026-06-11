#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1e18;

typedef pair<char,ll> pcl;
typedef vector<pcl> vpcl;
vpcl rle(string s) {
  vector<pair<char,ll>> res;
  char temp=s[0];
  ll count=0;
  for(ll i=0;i<s.size();i++) {
    if(temp==s[i]) {
      count++;
    }
    else {
      res.push_back(pair<char,ll>(temp,count));
      temp=s[i];
      count=1;
    }
    if(i==s.size()-1) {
      res.push_back(pair<char,ll>(temp,count));
    }
  }
  return res;
}

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n=s.size();
  vpcl check=rle(s);
  ll ans=0;
  if(check.size()==1) {
    cout << n*k/2 << endl;
    return 0;
  }
  for(auto p:check) {
    ans+=p.second/2;
  }
  ans*=k;
  if(check[0].first==check[check.size()-1].first) {
    ans-=(k-1)*(check[0].second/2+check[check.size()-1].second/2-(check[0].second+check[check.size()-1].second)/2);
  }
  cout << ans << endl;
}