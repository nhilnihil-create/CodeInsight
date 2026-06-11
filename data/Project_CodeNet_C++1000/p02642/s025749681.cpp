#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define LOL cout<<'\n';
#define MOD 1000000007
#define sz(x) ((int)x.size())
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN

bool isPrime(int n){
  if(n<2) return 0;
  for(int i=2 ; i*i<=n ; i++){
    if(n%i==0) return 0;
  }
  return 1;
}

void solve(){
  int n; cin>>n;
  map<int,int> m;
  int r=0;
  for(int i=0,u ; i<n ; i++) cin>>u,m[u]++,r=max(r,u);
  int cnt[r+1];
  for(int i=0 ; i<=r ; i++) cnt[i]=1;
  for(auto x:m){
    for(int j=x.f,i=2 ; j*i<=r ; i++){
      cnt[j*i]=0;
    }
  }
  //for(int i=0 ; i<=r ; i++) cout<<cnt[i]<<' ';LOL
  int ans=0;
  for(auto x:m){
    if(x.s>1) continue;
    ans+=cnt[x.f];
  }
  cout<<ans;LOL
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}
