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
  int N,M;
  string S;
  cin >> N >> M >> S;
  reverse(S.begin(),S.end());
  vi s(N+2);
  rep(i,N+1) s[i+1]=s[i]+(int)(S[i]-'0');
  
  int now=0;
  vi ans;
  bool flag=true;
  while(now<N) {
    if(now+M>=N) {
      ans.push_back(N-now);
      break;
    }
    if(S[now+M]==0) {
      ans.push_back(M);
      continue;
    }
    int l=now-1,r=now+M;
    while(r-l>1) {
      int m=(l+r)/2;
      if(s[now+M+1]-s[m+1]==now+M-m) r=m;
      else l=m;
    }
    if(r==now) {
      flag=false;
      break;
    }
    ans.push_back(r-now);
    now=r;
  }
  
  if(flag) {
    reverse(ans.begin(),ans.end());
    for(int x:ans) cout << x << ' ';
    cout << endl;
  }
  else cout << -1 << endl;
}