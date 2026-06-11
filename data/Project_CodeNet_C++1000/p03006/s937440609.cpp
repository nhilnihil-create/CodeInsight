#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  int n;
  cin >> n;
  vector<pll> p(n);
  for(int i=0;i<n;i++) {
    ll x,y;
    cin >> x >> y;
    p[i]=pll(x,y);
  }
  sort(p.begin(), p.end());
  map<pll,ll> pq;
  for(int i=0;i<n-1;i++) {
    for(int j=i+1;j<n;j++) {
      pll temp=pll(p[j].first-p[i].first,p[j].second-p[i].second);
      pq[temp]++;
    }
  }
  ll many=0;
  for(auto num:pq) {
    many=max(many,num.second);
  }
  cout << n-many << endl;
}