#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int MOD=1e9+7;

ll power(ll a, int b) {
  if(!b) return 1;
  ll c = power(a, b/2);
  if(b%2) return c*c%MOD*a%MOD;
  return c*c%MOD;
}

int main() {
  int S;
  cin >> S;
  vl pro(S,1);
  rep(i,S-1) (pro[i+1]=pro[i]*(i+1))%=MOD;
  
  ll ans=0;
  for(int k=1;3*k<=S;k++)
    (ans+=pro[S-2*k-1]*power(pro[S-3*k],MOD-2)%MOD*power(pro[k-1],MOD-2)%MOD)%=MOD;
  
  cout << ans << endl;
}