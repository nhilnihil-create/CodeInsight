#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const ll INF = 1e18 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int cnt[220000];
vector<int> vec[220000];

void dfs(int x, int p){
  cnt[x] += cnt[p];
  for(int y : vec[x]){
    if(y == p) continue;
    dfs(y, x);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    vec[a].push_back(b);vec[b].push_back(a);
  }

  fill(cnt, cnt + 220000, 0);
  rep(i, q){
    int p, x;
    cin >> p >> x;
    p--;
    cnt[p] += x;
  }
  dfs(0, -1);
  rep(i, n) printf("%d%c", cnt[i], i == n-1 ? '\n' : ' ');
}
  
  