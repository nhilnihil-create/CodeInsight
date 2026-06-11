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

ll power(ll a, int b) {
  if(!b) return 1;
  ll c = power(a, b/2);
  if(b%2) return c*c%INF*a%INF;
  return c*c%INF;
}

ll factorial(ll a) {
  if(!a) return 1;
  return a*factorial(a-1)%INF;
}

int main() {
  int X,Y;
  cin >> X >> Y;
  
  ll ans=0;
  if((X+Y)%3==0&&X<=2*Y&&Y<=2*X) {
    ll m=(2*Y-X)/3,n=(2*X-Y)/3;
    ans=factorial(m+n)*power(factorial(m),INF-2)%INF*power(factorial(n),INF-2)%INF;
  }
  
  cout << ans << endl;
}