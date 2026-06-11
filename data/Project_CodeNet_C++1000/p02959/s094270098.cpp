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
  vi A(N+1),B(N);
  rep(i,N+1) cin >> A[i];
  rep(i,N) cin >> B[i];
  
  ll ans=0;
  rep(i,N) {
    if(B[i]<=A[i]) ans+=B[i];
    else {
      B[i]-=A[i];
      ans+=A[i];
      if(B[i]<=A[i+1]) {
        ans+=B[i];
        A[i+1]-=B[i];
      }
      else {
        ans+=A[i+1];
        A[i+1]=0;
      }
    }
  }
  
  cout << ans << endl;
}