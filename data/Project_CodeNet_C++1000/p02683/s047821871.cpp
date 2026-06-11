#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  const int INF = 100000000;
  int n,m,x;cin >>n>>m>>x;
  vector<int> c(n);
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;++i){
    cin >> c[i];
    for(int j=0;j<m;++j)cin >> a[i][j];
  }
  int min_out=INF;
  for (int bit=0;bit < (1<<n); ++bit) {
    int tmp_c = 0;
    vector<int> tmp(m,0);
    for (int i = 0; i < n ; ++i) {
      if (bit & (1<<i)) {
        for(int j=0;j<m;++j) tmp[j] += a[i][j];
        tmp_c += c[i];
      }
    }
    if(x<=*min_element(tmp.begin(),tmp.end())) min_out = min(min_out,tmp_c);
  }
  if(min_out==INF){
    cout << -1 << endl;
  } else {
    cout << min_out << endl;
  }
  return 0;
}
