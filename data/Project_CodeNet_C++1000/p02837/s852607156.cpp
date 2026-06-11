#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll a[n];
  vector<vector<vector<ll>>> v(n);

  for(ll i=0;i<n;i++){
    cin >> a[i];
    for(ll j=0;j<a[i];j++){
      ll x,y;
      cin >> x >> y;
      v[i].push_back({x-1,y});
    }
  }

  ll m=0;

  for(ll b=0;b<(1<<n);b++){
    bool ok=true;
    for(ll i=0;i<n;i++){
      if(b & (1<<i)){
        for(ll j=0;j<a[i];j++){
          if(v[i][j][1]==0 && (b & (1<<v[i][j][0]))==0);
          else if(v[i][j][1]==1 && (b & (1<<v[i][j][0]))!=0);
          else{
            ok=false;
            break;
          }
        }
      }
      if(!ok)break;
    }
    if(ok)m=max(m,(ll)__builtin_popcount(b));
  }

  cout << m << endl;

}