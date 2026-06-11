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
  int N;
  cin >> N;
  cout << (power(10,N)+2*(MOD-power(9,N))+power(8,N))%MOD << endl;
}