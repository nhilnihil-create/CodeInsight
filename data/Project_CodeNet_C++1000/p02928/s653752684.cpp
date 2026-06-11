#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,k;
  cin >> n >> k;
  vector<ll> v(n);
  vector<ll> cnt(2020,0);
  rep(i,n)cin >> v[i],cnt[v[i]]++;
  ll res = 0;
  ll sum = 0;
  for(int i = 1;i <= 2000;i++)(res += ((cnt[i]*sum)%MOD)*(((k-1)*k/2)%MOD)%MOD)%=MOD,sum += cnt[i];
  rep(i,n)for(int j = i+1;j < n;j++)if(v[i] > v[j])res = (res+k)%MOD;
  cout << res << endl;

  

  





  return 0;
}