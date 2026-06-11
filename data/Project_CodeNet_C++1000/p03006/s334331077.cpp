#include <iostream>
#include <cstring>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <list>
#include <numeric>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <math.h>
#include <stack>
#include <climits>
#include <bitset>
#include <utility>


using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// const ll INF = 1LL <<60;
const int INF = 10000;

//最小公倍数
ll gcd(ll x, ll y) {
  ll tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

//最大公倍数
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

ll lmax(ll s,ll t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

ll lmin(ll s,ll t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}
// ここから開始

int main(){
  int n;
  cin>>n;
  int x[n],y[n];
  vector<pair<int,int> > d;
  for(int i = 0; i < n; i++) cin>>x[i]>>y[i];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i==j) continue;
      else{
        d.push_back(make_pair(x[i]-x[j],y[i]-y[j]));
      }
    }
  }
  int ans = 0;
  for(auto a:d){
    int tmp = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(make_pair(x[i]-x[j],y[i]-y[j])==a) tmp++;
      }
    }
    // cout<<tmp<<endl;
    ans=max(tmp,ans);
  }
  cout<<n-ans<<endl;
  return 0;
}
