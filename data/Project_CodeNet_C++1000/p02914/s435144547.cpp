#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 10;
const int LOG = 60;
ll basis[LOG];
ll a[N];

void insert_basis(ll x){
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if((x & (1ll << i)) == 0) continue;
    if(basis[i] == 0){
      basis[i]=x;
      return;
    }
    x ^= basis[i];
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  ll xr = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i];
    xr ^= a[i];
  }
  ll d;
  for(int i = 1; i <= n; i ++ ){
    a[i] -= (a[i] & xr);
    insert_basis(a[i]);
  }
  ll ans = 0;
  for(int i = LOG - 1; i >= 0 ; i -- ){
    if((ans & (1ll << i))) continue;
    ans ^= basis[i];
    
  }
  cout << 2ll * ans + xr << "\n";
  return 0;
}