#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tc(t) int t; cin >> t; while (t--)
#define for0(i, n)  for(int i = 0; i < n; i++)
#define pb push_back
#define int long long 

void solve()
{
  int a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;
  int d1 = abs(a-b);
  int d2 = (v-w)*t;
  cout<<(d1 <= d2 ? "YES" : "NO");
}

signed main() {

  fio;
  //tc(tt) {
    solve();
    cout<<"\n";
  //}
  
  return 0;
}