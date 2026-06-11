#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

const ll MX = 1ll << 60;

int main(){
  
  int n;
  cin >> n;
  vector<ll> v(n+1);
  rep(i,n+1)cin >> v[i];
  vector<ll> s(n+2,0);
  for(int i= n+1;i > 0;i--)s[i-1] = s[i]+v[i-1];
  ll res = 0;
  ll pre = 1;
  rep(i,n+1){
    ll k = s[i+1],l;
    if(pre <= 1ll << 60)l = pre;
    else l = MX;
    l -= v[i];
    if(l < 0){
      cout << -1 << endl;
      return 0;
    }
    res += min(k,l)+v[i];
    //printf("depth = %d ,val = %d\n",i,min(k,l)+v[i]);
    if(min(k,l) <= (1ll << 60))pre = min(k,l)*2;
    else pre = MX;
  }
  cout << res << endl;




  return 0;
}