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
  int N,K;
  cin >> N >> K;
  vector<double> p(N),s(N+1);
  rep(i,N) {
    cin >> p[i];
    s[i+1]=s[i]+(p[i]+1)/2.0;
  }
  
  double ans=0;
  rep(i,N-K+1) ans=max(ans,s[i+K]-s[i]);
  
  cout << fixed << setprecision(10) << ans << endl;
}