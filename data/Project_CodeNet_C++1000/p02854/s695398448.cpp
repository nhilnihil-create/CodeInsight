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
  vl A(N),s(N+1);
  rep(i,N) {
    cin >> A[i];
    s[i+1]=s[i]+A[i];
  }
  
  ll ans=1e15;
  rep(i,N) ans=min(ans,abs(s[N]-2*s[i]));
  
  cout << ans << endl;
}