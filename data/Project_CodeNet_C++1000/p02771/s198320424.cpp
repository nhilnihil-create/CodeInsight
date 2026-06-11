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
  int a[3];
  rep(i,3)  cin>>a[i];
  sort(a,a+3);
  set<int> ans;
  rep(i,3)  ans.insert(a[i]);
  if(sz(ans) == 2)  cout<<"Yes";
  else  cout<<"No";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  #endif
  int t = 1;
  pre();
  //cin>>t;
  rep(i,t)  {
    solve();
    cout<<'\n';
  }
  return 0;
}
