#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){

  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll sum_0 = 0;
  ll sum_1 = 0;

  REP(i,n){
    if(i%2 == 0)sum_0 += a[i];
    else sum_0 -= a[i];
  }
  sum_1 += a[0];
  REP2(i,1,n){
    if(i%2 == 1)sum_1 += a[i];
    else sum_1 -= a[i];
  }

  vector<ll> m(n);
  m[0] = sum_0;
  m[1] = sum_1;

  REP2(i,2,n){
    if(i%2 == 0){
      sum_0 = sum_0 -2*a[i-2]+2*a[i-1];
      m[i] = sum_0;
    }

    else{
      sum_1 = sum_1 - 2*a[i-2]+2*a[i-1];
      m[i] = sum_1;
    }

  }

  for(auto x : m) cout << x << " ";
  cout <<  endl;


  return 0;
}
