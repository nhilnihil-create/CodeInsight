#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
vector<vector<ll>> graph(1000000);
vector<ll> res(1000000);
vector<bool> seen(1000000);
ll v;
long long mod = 1000000007;
long long power(long long m,long long n){
    long long res = 1;
    if(n > 0){
        res = power(m,n / 2);
        if(n % 2 == 0){
            res = (res * res) % mod;
        }
        else{
            res = (((res * res) % mod) * m) % mod;
        }
    }
    return res;
}
void dfs(int p){
    ll size = 0;
    size = graph[p].size();
    seen[p] = true;
    //res[p] += size - 1;
    /*if(p != 0)*/res[p]++;
    for(int i = 0;i < size;i++){
        ll memo = 0;
        memo = graph[p][i];
        if(seen[memo])continue;
        res[p]++;
        //res[memo] = res[p] + 1;
        dfs(memo);
    }
    res[p]--;
}
int main(){
  ll k;
  cin >> v >> k;
  if(k == 1){
    if(v == 1)cout << k << endl;
    else cout << 0 << endl;
    return 0;
  }
  ll e = 0;
  e = v - 1;
  for(int i = 0;i < e;i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(0);
  //for(int i = 0;i < v;i++)cout << res[i] << endl;
  vector<ll> fac(1000000);
  fac[0] = 1;
  for(int i = 1;i < fac.size();i++)fac[i] = fac[i - 1] * i,fac[i] %= mod;
  ll ans = 0;
  ans = 1;
  ans *= k;
  //cout << ans << endl;
  for(int i = 0;i < v;i++){
    if(res[i] == 0)continue;
    if(i == 0){
      if(k - 1 - res[i] < 0){
        ans *= 0;
        continue;
      }
      ans *= fac[k - 1],ans %= mod;
      ans *= power(fac[k - 1 - res[i]],mod-2);
    }
    else{
      if(k - 2 - res[i] < 0){
        ans *= 0;
        continue;
      }
      ans *= fac[k - 2],ans %= mod;
      ans *= power(fac[k - 2 - res[i]],mod-2);
    }
    ans %= mod;
    //cout << i << " " << ans << endl;
  }
  cout << ans << endl;
}