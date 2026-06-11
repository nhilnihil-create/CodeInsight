//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=1e9;
const ll INF=1e18;
using P=pair<int,int>;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int n,x[55]={},y[55]={},cnt=0;
  cin >> n;
  map<pair<int,int>,int> mp;
  for(int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(i!=j) {
        mp[make_pair(x[i]-x[j],y[i]-y[j])]++;
        cnt=max(cnt,mp[make_pair(x[i]-x[j],y[i]-y[j])]);
      }
    }
  }
  cout << n-cnt << endl;
}