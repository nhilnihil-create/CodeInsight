#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll GCD(ll a, ll b){
  if(b==0) return a;
  else return GCD(b, a%b);
}

ll LCM(ll a, ll b){
  if(a<b) swap(a,b);
  return a/GCD(a,b)*b;
}
 
int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  ll mod = 1000000007;
  vector<ll> inv(200005);
  inv[0] = 0;
  inv[1] = 1;
  for(int i=2; i<=200001; i++){
    inv[i] = -(mod/i)*inv[mod%i];
    inv[i] %= mod;
    if(inv[i]<0) inv[i] += mod;
  }
  vector<ll> comb(200005);
  comb[0] = 1;
  comb[1] = n;
  for(int i=2; i<=min(int(n),200001); i++){
    comb[i] = comb[i-1]*inv[i];
    comb[i] %= mod;
    comb[i] *= n-i+1;
    comb[i] %= mod;
  }
  ll ans = 1;
  ll tmp = 2;
  while(n>0){
    if(n%2){
      ans *= tmp;
      ans %= mod;
    }
    n /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  ans--;
  ans -= comb[a];
  ans -= comb[b];
  ans %= mod;
  if(ans<0) ans += mod;
  cout << ans << endl;
  return 0;
}
