#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;
template<typename T> void caut(T a, T b, T c){cout<<"("<<a<<","<<b<<","<<c<<") ";}
template<typename T> void caut(T a, T b){cout<<"("<<a<<","<<b<<") ";}
template<typename T> void caut(T a){cout<<"("<<a<<") ";}

const ll M = 998244353;
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}

int main(){
  int n; cin>>n;
  ll an = 1;
  ll b[n]={}; bool ng=false;
  for(int i=0;i<n;i++) {
    ll a; cin>>a; b[a]++;
    if (i==0&&a!=0) ng=true;
    else if (i!=0&&a==0) ng=true;
  }
  for(int i=0;i<n-1;i++) {
    an *= mod_pow(b[i], b[i+1]);
    an %= M;
  }
  if (ng) an=0;
  cout<<an<<endl;
}
