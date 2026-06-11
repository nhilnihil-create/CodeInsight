#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;

int 
main()
{
  int N; cin >> N;
  map<string, ll> m;
  string s;
  rep(i, 0, N){
    string s; cin >> s;
    sort(s.begin(), s.end());
    m[s] += 1;
  }

  ll ans = 0;
  for(auto num: m){
    if(num.second >= 2) ans += (num.second * (num.second -1)) / 2;
  }

  cout << ans << endl;

}