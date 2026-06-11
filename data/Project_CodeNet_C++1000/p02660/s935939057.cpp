#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

int 
main()
{

  ll N; cin >> N;

  vector<pair<ll, ll>> arr;
  ll ori = N;
  for(ll i = 2; i * i <= N; ++i){
    if(N % i != 0) continue;
    ll ex = 0;
    while(N % i == 0){
      ++ex;
      N /= i;
    }
    arr.push_back({i, ex});
  }
  if(N != 1) arr.push_back({N, 1});

  ll ans = 0;
  for(auto x: arr){
    ll count = 0;
    while(x.second > count){
      ++count;
      rep(i, 0, count) ori /= x.first;
      x.second -= count;
    }
    ans += count;
  }

  cout << ans << endl;

}