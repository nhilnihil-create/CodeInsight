#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7;

int main() {
  ll n,k; cin>>n>>k;
  ll ans=0;
  // n+1個からk個以上の数を選び出す
  // 選ぶ個数が異なる場合、合計値は同じにはならない
  // 選ぶ数がk~n+1個の場合まで式に当てはめて足していく
  for(ll i=k; i<=n+1; i++) {
    ll minNum = (i*(i-1))/2;
    ll maxNum = i*n-minNum;
    (ans+=maxNum-(minNum-1))%=MOD;
    //cout << "i: " << i << ", min : " << minNum << ", max : " << maxNum << endl;
  }
  cout << ans << endl;
}
