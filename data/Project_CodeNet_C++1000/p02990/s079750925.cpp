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

ll power(ll a, int b) {
  if(!b) return 1;
  ll c = power(a, b/2);
  if(b%2) return c*c%INF*a%INF;
  return c*c%INF;
}

int main() {
  int N,K;
  cin >> N >> K;
  
  vl fact(N+1,1);
  rep(i,N) fact[i+1]=fact[i]*(i+1)%INF;
  
  rep2(i,1,K+1) {
    if(i==1)
      cout << N-K+1 << endl;
    else if(i<=N-K-1)
      cout << fact[N-K+1]*fact[K-1]%INF*power(fact[i]*fact[N-K-i+1]%INF*fact[i-1]%INF*fact[K-i]%INF,INF-2)%INF << endl;
    else if(i==N-K)
      cout << (N-K+1)*fact[K-1]%INF*power(fact[i-1]*fact[K-i]%INF,INF-2)%INF << endl;
    else if(i==N-K+1)
      cout << fact[K-1]*power(fact[i-1]*fact[K-i]%INF,INF-2)%INF << endl;
    else cout << 0 << endl;
  }
}