#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repA(i,n) for(int i=n; i>=0; i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (ll)(a.size())
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;//1e9+7

void solve() {
  int n,k;  cin>>n>>k;
  vector<int> a(n);
  rep(i,n)  cin>>a[i];
  while(k--) {
    vector<int> b(n+1,0);
    rep(i,n) {
      int from = max(0,i-a[i]);
      int to = min(n-1,i+a[i]);
      b[from]++;
      b[to+1]--;
    }
    bool changed = false;
    rep(i,n) {
      changed |= (a[i]!=b[i]);
      a[i] = b[i];
      b[i+1] += b[i];
    }
    if(!changed)  break;
  }
  rep(i,n)  cout<<a[i]<<' ';
  cout<<'\n';
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif
  ll t = 1;
//  cin>>t;
  rep(i,t)  {
    solve();
  //  cout<<'\n';
  }
  return 0;
}
