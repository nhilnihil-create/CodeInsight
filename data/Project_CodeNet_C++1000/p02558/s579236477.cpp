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
#include<atcoder/dsu>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  int n,q;
  cin >> n >> q;
  atcoder::dsu d(n);
  for(int i=0;i<q;i++){
    ll t,u,v;
    cin >> t >> u >> v;
    if(t==0){
      d.merge(u,v);
    }else{
      if(d.same(u,v)) cout <<1<<"\n";
      else cout <<0<<"\n";
    }
  }
}
