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
  ll K;
  cin >> N >> K;
  vi A(N);
  rep(i,N) cin >> A[i];
  
  vl count(N),count2(N);
  rep(i,N) {
    rep(j,N) {
      if(A[i]>A[j]) {
        if(i<j) count[i]++;
        else count2[i]++;
      }
    }
  }
  ll ans=0;
  ll x=K*(K+1)/2%INF,y=K*(K-1)/2%INF;
  rep(i,N) {
    ans=(ans+count[i]*x%INF)%INF;
    ans=(ans+count2[i]*y%INF)%INF;
  }
  
  cout << ans << endl;
}