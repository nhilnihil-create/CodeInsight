#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vector<double> v(N);
  rep(i,N) cin >> v[i];
  sort(v.begin(),v.end());
  
  double ans=v[0];
  rep2(i,1,N) ans=(ans+v[i])/2;
  
  cout << fixed << setprecision(5) << ans << endl;
}