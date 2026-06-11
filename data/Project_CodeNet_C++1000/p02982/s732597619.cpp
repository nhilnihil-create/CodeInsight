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
  ll n,d,ans=0;cin>>n>>d;
  vector<lvector> points(n,lvector(d,0));
  rep(i,n)rep(j,d) cin>>points[i][j];
  for(ll i=0;i<n-1;++i) {
    for(ll j=i+1;j<n;++j) {
      ll dist=0;
      rep(k,d) dist+=(points[i][k]-points[j][k])*(points[i][k]-points[j][k]);
      ll v=round(sqrt(dist));
      if(dist==v*v) ans++;
    }
  }
  print(ans);
  return 0;
}