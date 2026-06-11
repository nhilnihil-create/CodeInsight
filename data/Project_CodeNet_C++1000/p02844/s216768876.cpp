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
  string S;
  cin >> N >> S;
  
  vb check(10);
  vvb checkback(N,vb(10)),checkfront(N,vb(10));
  rep(i,N) {
    rep(j,10) {
      if(check[j]) checkback[i][j]=true;
    }
    check[S[i]-'0']=true;
  }
  reverse(S.begin(),S.end());
  check=vb(10);
  rep(i,N) {
    rep(j,10) {
      if(check[j]) checkfront[N-i-1][j]=true;
    }
    check[S[i]-'0']=true;
  }
  vector<vvb> count(10,vvb(10,vb(10)));
  reverse(S.begin(),S.end());
  rep(i,N) {
    rep(l,10) {
      rep(r,10) {
        if(checkback[i][l]&&checkfront[i][r]) count[S[i]-'0'][l][r]=true;
      }
    }
  }
  int ans=0;
  rep(i,10) {
    rep(j,10) {
      rep(k,10) {
        if(count[i][j][k]) ans++;
      }
    }
  }
  
  cout << ans << endl;
}