#include <bits/stdc++.h>
#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int k,q,d[5100],dd[5100];
signed main(){
  cin>>k>>q;rep(i,k)cin>>dd[i];
  rep(_,q){
    int n,x,m, zero = 0;cin>>n>>x>>m;
    x %= m;
    rep(i,k){
      d[i] = dd[i] % m;
      if(!d[i])zero++;
    }
    int sum = 0;
    rep(i,k)sum += d[i];
    sum *= (n-1)/k;
    zero *= (n-1)/k;
    sum += x;
    rep(i,(n-1)%k){
      sum += d[i];
      if(!d[i])zero++;
    }
    int ret = n-1-zero-(sum/m);
    cout << ret << endl;
  }
}
