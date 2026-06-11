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

int main(){
  ll T1, T2; cin >> T1 >> T2;
  ll A1, A2; cin >> A1 >> A2;
  ll B1, B2; cin >> B1 >> B2;

  ll D1 = (A1 - B1) * T1;
  ll D2 = (A1 - B1) * T1 + (A2 - B2) * T2;

  if (D1 == 0 || D2 == 0){
    cout << "infinity" << endl;
    return 0;
  }

  if ((D1 < 0 && D2 < 0) || (D1 > 0 && D2 > 0)){
    cout << 0 << endl;
    return 0;
  }

  ll N = abs(D1/D2);

  if (D1 % D2 == 0) cout << 2 * N << endl;
  else cout << 2 * N + 1 << endl;

  return 0;
}
