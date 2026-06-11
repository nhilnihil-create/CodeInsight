#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(size_t i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int,int>;
using pii = pair<int,int>;
using ti3 = tuple<int,int,int>;

int main(){
  ll n; cin>>n;
  vi d(n); REP(i,n) cin>>d[i];
  sort(d.begin(),d.end());
  cout<<d[n/2]-d[n/2-1]<<endl;
}