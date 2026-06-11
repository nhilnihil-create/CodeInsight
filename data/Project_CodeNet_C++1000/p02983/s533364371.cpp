#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll l,r,ans;cin>>l>>r;
  if(r-l>=2018) ans=0;
  else {
    ans=1e9;
    for(ll i=l;i<r;++i)for(ll j=i+1;j<=r;++j) ans=min(ans,(i*j)%2019);
  }
  print(ans);
  return 0;
}