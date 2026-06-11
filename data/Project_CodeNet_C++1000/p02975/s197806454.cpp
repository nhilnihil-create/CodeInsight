#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  map<ll,ll> a;
  for(ll i=0;i<n;i++) {
    ll temp=0;
    cin >> temp;
    a[temp]++;
  }
  if(a.size()==3&&n%3==0) {
    bool flag=true;
    ll check=0;
    for(auto p:a) {
      check=check^p.first;
      if(p.second!=n/3) {
        flag=false;
      }
    }
    if(check!=0) flag=false;

    if(flag) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  else if(a.size()==1&&a[0]==n) {
    cout << "Yes" << endl;
    return 0;
  }
  else if(a.size()==2&&a[0]==n/3&&n%3==0) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}