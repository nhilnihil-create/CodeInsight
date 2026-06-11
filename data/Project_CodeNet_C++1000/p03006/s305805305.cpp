#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin>>N;
  vector<vector<ll>> ball(N,vector<ll>(2));
  for(ll i = 0LL; i < N; i++) cin>>ball[i][0]>>ball[i][1];
  ll ans = 0LL;
  map<pair<int,int>,int> mp;
  for(ll i = 0LL; i < N; i++) {
    for(ll j = 0LL; j < N; j++) {
      if(i==j)continue;
      ll p = ball[i][0]-ball[j][0];
      ll q = ball[i][1]-ball[j][1];
      mp[make_pair(p,q)]++;
    }
  }
  int m = 0;
  for(auto x:mp){
    chmax(m,x.second);
  }
  cout<<N-m<<endl;
}