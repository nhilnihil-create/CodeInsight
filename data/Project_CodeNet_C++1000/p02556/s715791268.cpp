#include <bits/stdc++.h>
#include <ostream>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007, INF = 1e10;

int main(){
  int n;
  long long zmi=2e9,zma=-2e9,wmi=2e9,wma=-2e9;
  cin>>n;
  while(n--){
    long long x,y;
    cin>>x>>y;
    zmi=min(zmi,x+y);
    zma=max(zma,x+y);
    wmi=min(wmi,x-y);
    wma=max(wma,x-y);
  }
  cout<<max(zma-zmi,wma-wmi)<<"\n";
}
