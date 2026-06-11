#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  int n;
  cin >> n;
  ll x[n];
  ll y[n];
  rep(i,n)
    cin >> x[i] >> y[i];
  ll sax[n][n];
  ll say[n][n];
  rep(i,n){
    rep(j,n){
      sax[i][j]=x[i]-x[j];
      say[i][j]=y[i]-y[j];
    }
  }
  map<pair<ll,ll>,int> m;
  rep(i,n){
    rep(j,n){
      if(i==j)continue;
      if(!m.count(make_pair(sax[i][j],say[i][j]))){
        m[make_pair(sax[i][j],say[i][j])]=1;
        continue;
      }
      m[make_pair(sax[i][j],say[i][j])]++;
    }
  }
  int ma=0;
  for(auto p:m)
    ma=max(p.second,ma);
  cout << n-ma << endl;  
      
}