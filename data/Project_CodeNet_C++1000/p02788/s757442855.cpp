#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;
using pll = pair<ll, ll>;

int main(){
  int n;
  ll d, a;
  cin >> n >> d >> a;
  vector<pll> xh(n);
  for(int i = 0; i < n; ++i){
  	cin >> xh[i].first >> xh[i].second;
  }

  sort(xh.begin(), xh.end());
  ll total = 0;
  queue<pll> que;
  ll ans = 0;
  for(int i = 0; i < n; ++i){
  	ll x = xh[i].first;
  	ll h = xh[i].second;
  	while(que.size() && que.front().first < x){
  		total -= que.front().second;
  		que.pop();
  	}
  	h -= total;
  	if(h > 0){
  		ll num = (h + a - 1) / a;
  		ans += num;
  		ll damage = num * a;
  		total += damage;
  		que.emplace(x + 2*d, damage);
  	}
  }

  cout << ans << endl;
  return 0;
}
