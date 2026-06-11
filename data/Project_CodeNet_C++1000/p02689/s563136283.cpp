#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main(){
  int n,m; cin >> n >> m;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];

  vector<bool> chk(n, true);
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    a--; b--;
    if(h[a] <= h[b]) chk[a] = false;
    if(h[b] <= h[a]) chk[b] = false;
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(chk[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
