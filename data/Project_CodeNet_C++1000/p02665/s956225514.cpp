#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i >= b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define ll long long
#define pb push_back
#define sz(v) v.size()
#define pln(a)  cout<<a;
#define rr return 0;
#define rr1 return 1;
#define vr return;
#define int long long 

void solve()
{
  int n;
  cin>>n;
  vector<int>v(n+1);
  for0(i, n+1)  cin>>v[i];
  
  vector<int>mx(n+1);
  mx = v;
  bloop(i, n-1, 0) {
    mx[i] += mx[i+1];
  }
  
  
  int ans = 0, vi = 1;
  for0(i, n+1) {
    if(i != 0)
      vi = min(2*vi, mx[i]);
    ans += vi;
    vi -= v[i];
    if(vi < 0) {
      cout<<"-1";
      vr;
    }
  }
  
  cout<<ans;
}

signed main() {

  fio;
  
  
  //tc(t) {
    solve();
    pln("\n");
  //}
  
  rr;
}