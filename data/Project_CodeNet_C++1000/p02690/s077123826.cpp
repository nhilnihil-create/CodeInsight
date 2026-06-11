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
  int x; cin>>x;
  vector<pair<int,int>> v;
  for(int i=0 ; i*i*i*i*i<=1e18 ; i++){
      v.pb({i*i*i*i*i,i});
  }
  vector<int> ans;
  for(int i=0 ; i<sz(v) ; i++){
    for(int j=0 ; j<=i ; j++){
      if(x==v[j].f-v[i].f){
        cout<<v[j].s<<' '<<v[i].s;LOL
        return;
      }
      else if(x==v[i].f-v[j].f){
        cout<<v[i].s<<' '<<v[j].s;LOL
        return;
      }
      else if(x==v[i].f+v[j].f){
        cout<<v[i].s<<' '<<-v[j].s;LOL
        return;
      }
      else if(x==-v[i].f-v[j].f){
        cout<<-v[i].s<<' '<<v[j].s;LOL
        return;
      }
    }
  }
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
