#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m;
  cin >> n >> m;
  
  vector<ll> vote(n);
  rep(i, n)
    cin >> vote.at(i);
  
  sort(vote.begin(), vote.end(), greater<ll>() );
  ll sum = 0;
  
  rep(i, n)
    sum += vote.at(i);
  
  if(vote.at(m-1) * 4 * m >= sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}