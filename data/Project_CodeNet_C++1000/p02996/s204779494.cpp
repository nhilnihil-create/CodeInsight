#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

int main(){
  int n; scanf("%d", &n);
  vector<P> data(n);
  for(int i = 0; i < n; i++) scanf("%lld %lld", &data[i].second, &data[i].first);
  sort(data.begin(), data.end());
  ll now = 0;
  bool ok = true;
  for(int i = 0; i < n; i++){
    now += data[i].second;
    if(now > data[i].first) ok = false;
  }
  if(ok) puts("Yes");
  else puts("No");
}