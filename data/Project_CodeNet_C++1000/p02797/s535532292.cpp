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
  int N,K,S;
  cin >> N >> K >> S;
  vi A(N);
  if(S<1e9) {
    rep(i,K) cout << S << ' ';
    rep2(i,K,N) cout << S+1 << ' ';
    cout << endl;
  }
  else {
    rep(i,K) cout << S << ' ';
    rep2(i,K,N) cout << 1 << ' ';
    cout << endl;
  }
}