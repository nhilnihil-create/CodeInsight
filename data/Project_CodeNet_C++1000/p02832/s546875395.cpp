#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
#define ll long long
#define ld long double
#define ALL(x) begin(x),end(x)
     
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  //1,2,3,・・・,nで既に整列している場合
  bool flag = true;
  rep(i,n) if(a[i] != i+1) flag = false;
  if(flag){
    cout << "0" << endl;
    return 0;
  }
  //1,1,1,1,1,1・・・となっている場合
  bool fflag = true;
  rep(i,n) if(a[i]!=1) fflag = false;
  if(fflag){
    cout << n-1 << endl;
    return 0;
  }
  
  ll search = 1; //検索数字
  ll dist = 0;
  ll ans = -1;
  rep(i,n){
    auto itr = find(a.begin()+dist,a.end(),search);
    if(itr != a.end()) search++, dist = distance(a.begin(),itr);
    else break;
  }
  if(dist!=0)cout << n-search+1 << endl;
  else cout << "-1" << endl;
}