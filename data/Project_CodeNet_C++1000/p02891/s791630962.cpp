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

string S; ll K;
vector <pair<char, ll>> P;

int main(){
  cin >> S >> K;
  
  ll cnt = 1;
  for (int i = 1; i < S.length(); i++){
    if (S[i] == S[i-1]){
      cnt++;
    }else{
      P.push_back({S[i-1], cnt});
      cnt = 1;
    }
  }
  P.push_back({S[S.length()-1], cnt});

  int V = P.size();

  if (V == 1){
    ll ans = S.length();
    cout << ans * K / 2 << endl;
    return 0;
  }
  if (P[0].fi != P[V-1].fi){
    ll ans = 0;
    for (int i = 0; i < V; i++){
      ans += P[i].se / 2;
    }
    cout << ans * K << endl;
    return 0;
  }

  ll ans = 0;
  for (int i = 1; i < V-1; i++){
    ans += P[i].se/ 2;
  }
  ans *= K;
  ans += (P[0].se + P[V-1].se) / 2 * (K-1);
  ans += P[0].se / 2 + P[V-1].se / 2;

  cout << ans << endl;


  return 0;
}
