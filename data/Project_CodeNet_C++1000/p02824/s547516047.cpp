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
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,m,v,p;
  cin >> n >> m >> v >> p;
  vector<ll> a(n);
  ll l = -1,r=n,h;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end(),greater<ll>());
  while(r-l>1){
    h = (r+l)/2;
    ll sum = 0,val=a[h]+m;
    for(int i=0;i<n;i++){
      if(i<p-1||i>=h){
        sum += m;
      }else{
        sum += max(0ll,val-a[i]);
      }
    }
    if((h<p-1)||((a[h]+m>=a[p-1])&&(sum>=m*v))){
      l = h;
    }else{
      r = h;
    }
  }
  cout << l+1<<endl;
}
