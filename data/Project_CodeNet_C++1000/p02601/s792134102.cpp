// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
ll a,b,c,k;
bool can = false;
void solve(ll x,ll y,ll z,ll i){
  if(k==i){
    if(y>x&&z>y){
      can = true;
    }
    return;
  }
  i++;
  solve(x*2,y,z,i);
  solve(x,y*2,z,i);
  solve(x,y,z*2,i);
}
signed main(){
  init_io();
  cin >> a >> b >> c >> k;
  solve(a,b,c,0);
  if(can) cout <<"Yes\n";
  else cout <<"No\n";
}
