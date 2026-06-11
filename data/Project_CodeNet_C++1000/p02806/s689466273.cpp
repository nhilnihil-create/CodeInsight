#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
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
  vector<string> s(N);
  vi t(N);
  rep(i,N) cin >> s[i] >> t[i];
  string X;
  cin >> X;
  
  int a;
  rep(i,N) {
    if(X==s[i]) {
      a=i;
      break;
    }
  }
  int ans=0;
  rep2(i,a+1,N) ans+=t[i];
  
  cout << ans << endl;
}