#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define LOL cout << '\n';
#define sz(x) ((int)x.size())
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define deb(x) cout << "[" << (#x) << "=" << x << "]" << '\n';
#define deb2(x,y) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "]" << '\n';
#define deb3(x,y,z) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "] [" << (#z) << "=" << z << "]" << '\n';

void solve(){
  int n,k; cin>>n>>k;
  vector<int> vis(n+10,0);
  for(int i=0,d,a ; i<k ; i++){
    cin>>d;
    while(d>0){
      cin>>a;
      vis[a]=1;
      --d;
    }
  }
  int cnt=0;
  for(int i=1 ; i<=n ; i++) cnt+=(vis[i]==0);
  cout<<cnt;LOL
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int _ = 1; //cin >> _;
  for(int i = 1 ; i <= _ ; i++){
    //cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}