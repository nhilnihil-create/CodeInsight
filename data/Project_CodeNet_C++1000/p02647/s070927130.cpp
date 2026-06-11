#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<60)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa system("pause");
#define dbg(x) cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)cerr<<x[_]<<' ';cerr<<'\n',aaa
#define dbgs(x) cerr<<(#x)<<"[stl]: ";for(auto _:x)cerr<<_<<' ';cerr<<'\n',aaa
#define dbgp(x) cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define maxn 200000

using namespace std;

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, k, i; cin >> n >> k;
  vi v(n), u(n+1);
  for (i = 0; i < n; i++) cin >> v[i];
  while (k && *min_element(all(v)) < n) {
    fill(all(u), 0);
    for (i = 0; i < n; i++) {
      u[max(0, i-v[i])]++;
      u[1+min(n-1, i+v[i])]--;
    }
    for (i = 0; i < n; i++) {
      if (i) u[i] += u[i-1];
      v[i] = u[i];
    }
    k--;
  }
  for (int x: v) cout << x << ' ';
  return 0;
}