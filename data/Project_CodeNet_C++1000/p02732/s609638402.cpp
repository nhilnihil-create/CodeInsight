#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int n; cin>>n;
  vector<ll>A(n);
  rep(i,n) cin>>A[i];
  map<ll, ll>mp;
  rep(i,n) mp[A[i]]++;
  ll ans = 0;
  for(auto p:mp){
    ans += p.second*(p.second-1)/2;
  }
  rep(i,n){
    if (mp[A[i]] == 1) cout << ans << endl;
    else{
      cout << ans-(mp[A[i]]-1) << endl;
    }
  }

}