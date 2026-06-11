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

int N, M;
ll A[int(1e5+5)], ans;
priority_queue <ll> que;

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> A[i]; que.push(A[i]);
  }

  for (int i = 0; i < M; i++){
    ll Q = que.top(); que.pop();
    que.push(Q / 2);
  }

  while (!que.empty()){
    ans += que.top(); que.pop();
  }
  cout << ans << endl;


  return 0;
}
