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
  int N; cin >> N;
  map<string, ll> m;
  vector<pair<ll, ll>> arr(N + 1);
  rep(i, 1, N + 1){
    int tmp; cin >> tmp;
    arr[i].first = i;
    arr[i].second = tmp;
    tmp = i - tmp;
    m["x" + to_string(tmp)] += 1;
  }

  ll ans = 0;
  rep(i, 1, N){
    ll comp = arr[i].first + arr[i].second;
    ans += m["x" + to_string(comp)];
  }

  cout << ans << endl;

}