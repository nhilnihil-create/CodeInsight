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
  int N,P;
  string S;
  cin >> N >> P >> S;
  
  vi a(N+1);
  int ten=1;
  ll ans=0;
  if(P!=2&&P!=5) {
    vl count(P);
    count[0]++;
    rep(i,N) {
      a[i+1]=(a[i]+(S[N-i-1]-'0')*ten)%P;
      count[a[i+1]]++;
      (ten*=10)%=P;
    }
  
    rep(i,P) ans+=count[i]*(count[i]-1)/2;
  }
  else {
    rep(i,N) {
      if(!((S[i]-'0')%P)) ans+=i+1;
    }
  }
  
  cout << ans << endl;
}