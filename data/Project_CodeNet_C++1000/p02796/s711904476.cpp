#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;

int n,ans = 0;
int now = -2e9;
vector<pair<int,int>> v;

int main(){
  cin >> n;
  rep(i,n){
    ll x,l = 0; cin >> x >> l;
    v.push_back(make_pair(x+l,x-l));
  }    
  sort(v.begin(),v.end());
    
  rep(i,n){
    if(v[i].second < now) continue;
      else{
        now = v[i].first;
        ans++;
      }
  }
  cout << ans << endl;
}