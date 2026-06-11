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

int X, Y, A, B, C;
priority_queue <Pli> que;

int main(){
  cin >> X >> Y >> A >> B >> C;
  for (int i = 0; i < A; i++){
    ll P; cin >> P;
    que.push({P, 0});
  }
  for (int i = 0; i < B; i++){
    ll Q; cin >> Q;
    que.push({Q, 1});
  }
  for (int i = 0; i < C; i++){
    ll R; cin >> R;
    que.push({R, 2});
  }

  ll ans = 0;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  while (cnt0 + cnt1 + cnt2 < X + Y){
    Pli Q = que.top(); que.pop();
    if (Q.se == 0 && cnt0 < X){
      ans += Q.fi; cnt0++;
    }
    if (Q.se == 1 && cnt1 < Y){
      ans += Q.fi; cnt1++;
    }
    if (Q.se == 2){
      ans += Q.fi; cnt2++;
    }
  }
  cout << ans << endl;

  return 0;
}
