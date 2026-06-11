#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}

int main() {
  int n,m; cin>>n>>m;
  int s[n], t[m+1]; m++; t[0]=-1;
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=1;i<m;i++) cin>>t[i];

  ll sm[m]={1};

  for(int i=0;i<n;i++) {
    ll su = 0;
    // 使わない場合 : sm_new[i] = sm_old[i]
    // 使う場合
    for(int j=0;j<m;j++) {
      ll tm = sm[j];
      if (s[i] == t[j]) add(sm[j],su);
      su += tm;
    }
    /*
    for(int j=0;j<m;j++) {
      cout<<sm[j]<<" ";
    } cout<<endl;*/
  }
  ll an=0;
  for(int i=0;i<m;i++) {
    add(an,sm[i]);
  }
  cout<<an<<endl;
}