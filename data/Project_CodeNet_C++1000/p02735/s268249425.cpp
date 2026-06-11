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

int H, W;
char S[105][105];
int di[2] = {0,1}, dj[2] = {1,0};
bool visited[105][105];
int cnt[105][105];

int main(){
  cin >> H >> W;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> S[i][j];
    }
  }

  priority_queue < pair<int, Pii>, vector<pair <int, Pii> >, greater<pair<int, Pii> > > que;

  if (S[0][0] == '.') que.push({0, {0, 0}});
  else que.push({1, {0, 0}});

  while (!que.empty()){
    pair <int, Pii> Q = que.top(); que.pop();
    if (visited[Q.se.fi][Q.se.se]) continue;
    
    visited[Q.se.fi][Q.se.se] = true;
    cnt[Q.se.fi][Q.se.se] = Q.fi;

    for (int k = 0; k < 2; k++){
      int I = Q.se.fi + di[k], J = Q.se.se + dj[k];
      if (0 <= I && I < H && 0 <= J && J < W){
        if (visited[I][J]) continue;
        if (S[Q.se.fi][Q.se.se] == '.' && S[I][J] == '#') que.push({Q.fi + 1, {I, J}});
        else que.push({Q.fi, {I, J}});
      }
    }
  }
  cout << cnt[H-1][W-1] << endl;
  return 0;
}
