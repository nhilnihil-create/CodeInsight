#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

string L; 
ll DP1[int(1e5+5)], DP2[int(1e5+5)];
int main(){
  cin >> L;
  int N = L.length();
  DP1[0] = 1; DP2[0] = 2;

  for (int i = 1; i < N; i++){
    DP1[i] += DP1[i-1] * 3 % MOD;
    if (L[i] == '0'){
      DP2[i] += DP2[i-1];
    }else{
      DP1[i] += DP2[i-1]; DP1[i] %= MOD;
      DP2[i] += DP2[i-1] * 2 % MOD;
    }
  }
  ll ans = (DP1[N-1] + DP2[N-1]) % MOD;
  cout << ans << endl;

  return 0;
}
