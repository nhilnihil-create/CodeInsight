#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;


int main(){
  int n;
  cin >> n;
  vector<ll> vx(n);
  vector<ll> vy(n);
  rep(i,n){
     ll x,y;
     cin >> x >> y;
     vx[i] = x-y;
     vy[i] = x+y;
  }
  ll maxvx = -(1LL << 60),minvx = 1LL << 60, maxvy = -(1LL << 60),minvy = 1LL << 60;
  rep(i,n){
    maxvx = max(maxvx,vx[i]);
    maxvy = max(maxvy,vy[i]);
    minvx = min(minvx,vx[i]);
    minvy = min(minvy,vy[i]);
  }
  cout << max(maxvx-minvx,maxvy-minvy) << endl;


  return 0;
}