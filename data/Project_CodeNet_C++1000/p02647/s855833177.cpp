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
using P=pair<ll,ll>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}

int main() {
  int n,k; cin>>n>>k;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];

  int t = 0;

  for(int i=0;i<k;i++) {
    bool end = true;
    for(int j=0;j<n;j++) {
      if (a[j] != n) {end = false; break;}
    }
    if (end) break;
    int sm[n]={};

    for(int j=0;j<n;j++) {
      int lf = max(0, j - a[j]);
      int ri = j + a[j] + 1;
      sm[lf]++;
      if (ri < n) sm[ri]--;
    }

    for(int j=1;j<n;j++){
      sm[j] += sm[j-1];
    }
    copy(sm,sm+n,a);
    t++;
  }
  
  for(int i=0;i<n;i++) {
    cout<<a[i]<<" ";
  } cout<<endl;
}