#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n,d,a,sum = 0;
  cin >> n >> d >> a;
  vector<pair<ll,ll>>x(n);
  vector<ll>pm(n+1),ac(n),it(n+1);
  for(int i =0; i<n; i++){
    cin >> x[i].first >> x[i].second;
    it[i] = x[i].first;
  }
  it[n] = 10000000000;
  sort(x.begin(),x.end());
  sort(it.begin(),it.end());
  
  for(ll i=0; i<n; i++){
    if(i>0) ac[i] = ac[i-1] - pm[i];
    x[i].second -= ac[i]*a;
    if(x[i].second <= 0)continue;
    ll count = x[i].second/a;
    if(x[i].second%a != 0)count++;
    ll fin = it[i]+d*2;
    ll Itre = upper_bound(it.begin(),it.end(),fin)-it.begin();
    pm[Itre]+=count;
    ac[i] += count;
    x[i].second -= count*a;
    sum += count;
  }
  
  
  cout << sum << endl;
  
  
}
