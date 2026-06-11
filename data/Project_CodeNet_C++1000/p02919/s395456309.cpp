#include<iostream>
#include<vector>
#include<functional>
#include<iomanip>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,ans=0;
  multiset<ll> idx_set;
  cin >> n;
  vector<ll> p(n),idx(n+1);

  for(int i=0;i<n;i++){
    cin >> p[i];
    idx[p[i]] = i+1;
  }

  idx_set.insert(0);
  idx_set.insert(0);
  idx_set.insert(n+1);
  idx_set.insert(n+1);

  for(int i=n;i>0;i--){
    auto it_x3 = idx_set.upper_bound(idx[i]);
    auto it_x2 = it_x3;
    it_x2--;
    auto it_x4 = it_x3;
    it_x4++;
    auto it_x1 = it_x2;
    it_x1--;

    ll x_1 = *it_x1,x_2 = *it_x2,x_3 = *it_x3,x_4 = *it_x4;
    
    ans += i*(x_2-x_1)*(x_3-idx[i]);

    ans += i*(x_4-x_3)*(idx[i]-x_2);
    idx_set.insert(idx[i]);

  }
  cout << ans << endl;
}

