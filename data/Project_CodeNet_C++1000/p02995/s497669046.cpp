#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll GCD(ll A, ll B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B; swap(A, B);
  }
  return B;
}

ll LCM(ll A, ll B){
  ll G = GCD(A, B);
  return A / G * B;
}

int main(){
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll ans = B / C - (A - 1) / C;
  ans += B / D - (A - 1) / D;

  ll L = LCM(C, D);
  ans -= B / L - (A - 1) / L;

  cout << (B - A + 1) - ans << endl;

  return 0;
}
