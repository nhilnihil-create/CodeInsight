#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  ll n; cin >> n;
  vector<ll> a(n),b(n);
  vector<pair<ll,ll>> task;
  rep(i,n){
    ll a,b; cin >> a >> b;
    pair<ll,ll> p = make_pair(b,a);
    task.push_back(p);
  }

  sort(all(task));

  ll time = 0;

  bool ans = true;

  rep(i,n){
    ll a = task.at(i).second,b = task.at(i).first;
    if(time + a > b) ans = false;
    time += a;
  }

  if(ans) puts("Yes");
  else puts("No");
}
