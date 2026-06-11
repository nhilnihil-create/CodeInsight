#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
ll facctorialMethod(ll k){
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
        sum *= i;
    return sum;
}

int main() {
  ll n; cin >> n;
  vector<P> data(n);
  rep(i, n)
    cin >> data[i].first >> data[i].second;
  sort(data.begin(), data.end());
  
  ll k = facctorialMethod(n);
  
  double ans = 0;
  do{
    rep(i, n-1){
      double dis=0;
      dis += (data[i+1].first-data[i].first)*(data[i+1].first-data[i].first);
      dis += (data[i+1].second-data[i].second)*(data[i+1].second-data[i].second);
      dis = sqrt(dis);
      ans += dis;
  }}while(next_permutation(data.begin(),data.end()));
  
  cout << fixed << setprecision(10);
  cout << ans / k << endl;
}