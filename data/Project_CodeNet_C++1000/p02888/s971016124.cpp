#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define repi(i,a,b) for(int i = (a); i<= (b); i++)
#define repA(i,n) for(int i=n; i>=0; i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)(a.size())

typedef long long ll;
typedef long double ld;
const ll mod = (ll)(1e9+7);//998244353;
const int N = (int)(2e6+5);

void pre() {

}

void solve() {
  int n;  cin>>n;
  vector<int> a(n);
  rep(i,n)  cin>>a[i];

  sort(all(a));

  ll ans = 0;

  //rep(i,n)  cout<<a[i]<<' ';  cout<<'\n';

  rep(i,n) {
    repi(j,i+1,n-1) {
      int k = (int)(lower_bound(all(a),a[i]+a[j]) - 1 - a.begin()) - j;
      ans += k;
  //    cout<<i<<' '<<j<<' '<<k<<'\n';
    }
  }
  cout<<ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif
  int t = 1;
  pre();
//  cin>>t;
  rep(i,t)  {
    //cout<<"\nCase #"<<(i+1)<<"\n";
    solve();
    cout<<'\n';
  }
  return 0;
}
