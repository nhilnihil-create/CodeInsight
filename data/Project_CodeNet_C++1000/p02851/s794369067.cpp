#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n+1);
  a[0] = 0;
  rep(i,n) cin >> a.at(i+1);
  rep(i,n) a.at(i+1)--;
  
  a.at(0) %= k;
  rep(i,n) a.at(i+1) = (a.at(i+1) + a.at(i))%k;
  map<ll,set<ll>> mp;
  rep(i,n+1){
    mp[a[i]].insert(i);
  }
  
  ll ans = 0;
  for(auto p:mp){
    queue<ll> q;
    for(auto z:p.second){
      while(!q.empty()){
        if(q.front() <= z-k){ q.pop();}
        else{ break;}
      }
      ans += (int)q.size();
      q.push(z);
      //cout << z<< endl;
    }
  }
  
  cout << ans << endl;
    
  return 0;
}

