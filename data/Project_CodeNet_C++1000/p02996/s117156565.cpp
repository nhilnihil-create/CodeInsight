#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n;
  cin >> n;
  vector<pair<ll,ll>> ps(n);
  for (int i = 0; i < n; i++) {
    ll a,b;
    cin >> a >> b;
    ps[i].second=a;
    ps[i].first=b;
  }
  sort(ps.begin(),ps.end());
  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=ps[i].second;
    if(sum>ps[i].first){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

