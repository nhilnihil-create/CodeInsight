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
#define MINF LONG_LONG_MIN

void solve(){
  int n; cin>>n;
  vector<int> a(n),p(n),s(n);
  for(int i=0 ; i<n ; i++){
    cin>>a[i];
    p[i]=a[i];
    s[i]=a[i];
  }
  for(int i=1 ; i<n ; i++) p[i]^=p[i-1];
  for(int i=n-2 ; i>=0 ; i--) s[i]^=s[i+1];
  for(int i=0 ; i<n ; i++) cout<<(p[i]^s[i])<<' ';LOL
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}